print("🚀 Giả lập Core IOT bắt đầu...")

import time
import json
import random
import paho.mqtt.client as mqtt

# ⚙️ MQTT Configuration
BROKER = "app.coreiot.io"
PORT = 1883
ACCESS_TOKEN = "RaJWiAN3wj6XlAZr2PjP"

# 🟢 Trạng thái relay
relay_states = {f"brsw{i}": False for i in range(1, 7)}

# 🌡️ Dữ liệu cảm biến
sensor_data = {
    "temperature": 25.0,
    "humidity": 50.0,
    "light": 200.0
}

# 📥 Callback khi kết nối thành công
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("[MQTT] ✅ Đã kết nối!")
        client.subscribe("v1/devices/me/rpc/request/+")
        client.subscribe("v1/devices/me/attributes/response/+")
        attr_req = json.dumps({"clientKeys": ",".join(sensor_data.keys())})
        client.publish("v1/devices/me/attributes/request/1", attr_req)
    else:
        print(f"[MQTT] ❌ Lỗi kết nối: {rc}")

# 📩 Callback khi nhận tin nhắn
def on_message(client, userdata, msg):
    try:
        payload = json.loads(msg.payload.decode())
        topic = msg.topic

        if topic.startswith("v1/devices/me/rpc/request/"):
            method = payload.get("method")
            value = payload.get("params")
            if method in relay_states:
                relay_states[method] = value
                print(f"[RPC] Công tắc {method} => {'BẬT' if value else 'TẮT'}")
                # Cập nhật trạng thái relay lên attribute
                # client.publish("v1/devices/me/attributes", json.dumps({method: value}))

    except Exception as e:
        print("❗ Lỗi xử lý message:", e)

# 🔁 Giả lập cảm biến
def update_fake_sensor():
    sensor_data["temperature"] = round(random.uniform(20, 60), 2)
    sensor_data["humidity"] = round(random.uniform(40, 100), 2)
    sensor_data["light"] = round(random.uniform(100, 800), 1)

# 🚀 Khởi tạo client
client = mqtt.Client("CORE_IOT_SIM")
client.username_pw_set(ACCESS_TOKEN)
client.on_connect = on_connect
client.on_message = on_message

client.connect(BROKER, PORT)
client.loop_start()

# 🔄 Gửi telemetry sensor mỗi 30s
try:
    while True:
        # update_fake_sensor()

        payload = json.dumps(sensor_data)
        print(f"[MQTT] 📤 Telemetry (sensor): {payload}")
        # client.publish("v1/devices/me/telemetry", payload)

        time.sleep(600)

except KeyboardInterrupt:
    print("🛑 Dừng giả lập.")
    client.loop_stop()
    client.disconnect()
