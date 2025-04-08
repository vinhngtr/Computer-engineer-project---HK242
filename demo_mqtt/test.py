print("Hello Core IOT")
import paho.mqtt.client as mqttclient
import time
import json
import random

BROKER_ADDRESS = "app.coreiot.io"
PORT = 1883
ACCESS_TOKEN = "iot_password"
ACCESS_USERNAME = "iot_username"

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
    print("Received: ", message.payload.decode("utf-8"))
    try:
        jsonobj = json.loads(message.payload)
        if jsonobj['method'].startswith("sw"):  # Ex: sw1, sw2, ...
            key = jsonobj['method']
            value = jsonobj['params']
            if key in relay_states:
                relay_states[key] = value
                print(f"[Relay] {key} => {'ON' if value else 'OFF'}")
                if key == "sw1":
                    relay_states["sw2"] = not value
                    print(f"[Logic] sw1 => sw2 = {'ON' if relay_states['sw2'] else 'OFF'}")
                elif key == "sw2":
                    relay_states["sw1"] = not value
                    print(f"[Logic] sw2 => sw1 = {'ON' if relay_states['sw1'] else 'OFF'}")
                # Gửi trạng thái ngược lại lên attributes
                client.publish('v1/devices/me/attributes', json.dumps(relay_states), 1)
    except Exception as e:
        print("Error in RPC:", e)

def connected(client, usedata, flags, rc):
    if rc == 0:
        print("Connected successfully!!")
        client.subscribe("v1/devices/me/rpc/request/+")
    else:
        print("Connection failed")

client = mqttclient.Client("IOT_SERVER")
client.username_pw_set(ACCESS_USERNAME, ACCESS_TOKEN)

client.on_connect = connected
client.connect(BROKER_ADDRESS, PORT)
client.loop_start()

client.on_subscribe = subscribed
client.on_message = recv_message

temp = 30
humi = 50

while True:
    # Gửi dữ liệu cảm biến + trạng thái 6 relay lên telemetry
    collect_data = {
        'temperature': temp,
        'humidity': humi,
        **relay_states  # Gửi luôn trạng thái các switch
    }
    client.publish('v1/devices/me/attributes', json.dumps(relay_states), 1)
    client.publish('v1/devices/me/telemetry', json.dumps(collect_data), 1)

    temp = random.randint(16, 40)  # temp từ 16 đến 40
    humi = random.randint(50, 100)  # humi từ 50 đến 100
    time.sleep(5)
