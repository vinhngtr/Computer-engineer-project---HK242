print("Hello Core IOT")

import paho.mqtt.client as mqttclient
import time
import json
import random

BROKER_ADDRESS = "app.coreiot.io"
PORT = 1883
ACCESS_TOKEN = "vns9s1vqy67gnpfccc6c"

relay_states = {
    "sw1": False,
    "sw2": False,
    "sw3": False,
    "sw4": False,
    "sw5": False,
    "sw6": False
}

def subscribed(client, userdata, mid, granted_qos):
    print("Subscribed...")

def recv_message(client, userdata, message):
    print("Received:", message.topic, message.payload.decode("utf-8"))
    try:
        if message.topic.startswith("v1/devices/me/rpc/request/"):
            # Handle RPC control
            jsonobj = json.loads(message.payload)
            if jsonobj['method'].startswith("sw"):
                key = jsonobj['method']
                value = jsonobj['params']
                if key in relay_states:
                    relay_states[key] = value
                    print(f"[Relay] {key} => {'ON' if value else 'OFF'}")
                    client.publish('v1/devices/me/attributes', json.dumps(relay_states), 1)

        elif message.topic.startswith("v1/devices/me/attributes/response/"):
            # Handle attribute response (both client and shared)
            data = json.loads(message.payload.decode())

            # Xử lý CLIENT attributes
            client_attr = data.get("client", {})
            temp_client = client_attr.get("temperature")
            humi_client = client_attr.get("humidity")

            if temp_client is not None:
                print(f"[CLIENT ATTR] temperature = {temp_client}")
            if humi_client is not None:
                print(f"[CLIENT ATTR] humidity = {humi_client}")

    except Exception as e:
        print("Error in on_message:", e)

def connected(client, userdata, flags, rc):
    if rc == 0:
        print("Connected successfully!!")
        client.subscribe("v1/devices/me/rpc/request/+")
        client.subscribe("v1/devices/me/attributes/response/+")
        # Gửi yêu cầu lấy CLIENT attributes
        client.publish("v1/devices/me/attributes/request/1", json.dumps({
            "clientKeys": "temperature,humidity"
        }))
    else:
        print("Connection failed with code", rc)

client = mqttclient.Client("IOT_SERVER")
client.username_pw_set(ACCESS_TOKEN)

client.on_connect = connected
client.on_subscribe = subscribed
client.on_message = recv_message

client.connect(BROKER_ADDRESS, PORT)
client.loop_start()

temp = 30
humi = 50

while True:
    collect_data = {
        'temperature': temp,
        'humidity': humi,
        **relay_states
    }

    # Cập nhật shared attributes với temp+2, humi+2 (nếu cần)
    shared_update = {
        "temperature": temp + 2,
        "humidity": humi + 2
    }
    client.publish("v1/devices/me/attributes", json.dumps(shared_update), 1)
    
    # Gửi trạng thái relay
    client.publish('v1/devices/me/attributes', json.dumps(relay_states), 1)

    # Gửi telemetry
    client.publish('v1/devices/me/telemetry', json.dumps(collect_data), 1)

    # Sinh dữ liệu mới
    temp = random.randint(16, 40)
    humi = random.randint(50, 100)
    time.sleep(5)
