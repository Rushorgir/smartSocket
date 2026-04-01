<p align="center">
		<img src="https://capsule-render.vercel.app/api?type=waving&color=0:FFFFFF,100:F5F5DC&height=200&section=header&text=smartSocket%20%7C%20ESP32%20IoT%20Power%20Control&fontSize=40&fontColor=000000&animation=fadeIn&fontAlignY=35" alt="smartSocket Banner"/>
</p>

<p align="center">
	<img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=600&size=22&pause=1000&color=F5F5DC&center=true&vCenter=true&width=700&lines=WiFi+Enabled+Smart+Socket+Control;Remote+Relay+Switching+with+Blynk;Built+With+ESP32+%26+Arduino" alt="Typing SVG"/>
</p>

<p align="center">
	<img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++"/>
	<img src="https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white" alt="Arduino"/>
	<img src="https://img.shields.io/badge/ESP32-E7352C?style=for-the-badge" alt="ESP32"/>
	<img src="https://img.shields.io/badge/Blynk-23C48E?style=for-the-badge" alt="Blynk"/>
	<img src="https://img.shields.io/badge/WiFi-0078D4?style=for-the-badge" alt="WiFi"/>
</p>

---

## 📌 Overview
smartSocket is an **ESP32-based IoT smart socket firmware** controlled through the **Blynk platform**.
It lets you remotely toggle a relay (power socket) from your phone while keeping startup behavior safe and predictable.

---

## ✨ Features
- 🎯 **Remote Relay Control** — Toggle connected load from Blynk app (V0)
- ⚡ **Fast ESP32 Runtime** — Lightweight firmware loop with stable control flow
- 🔒 **Safer Defaults** — Relay starts OFF at boot
- 🌐 **WiFi + Cloud Control** — Blynk-connected smart switching from anywhere
- 🧩 **Easy Customization** — Change relay pin, logic, and credentials quickly

---

## 📦 Installation
```bash
# Clone the repo
git clone https://github.com/Rushorgir/smartSocket.git
cd smartSocket

# Create local secrets file
cp secrets.h.example secrets.h

# Add your values inside secrets.h:
# auth = Blynk auth token
# ssid = WiFi SSID
# pass = WiFi password
```

---

## ▶️ Usage

```bash
# Compile for ESP32
arduino-cli compile --fqbn esp32:esp32:esp32 .

# Upload (replace port)
arduino-cli upload -p /dev/tty.usbserial-XXXX --fqbn esp32:esp32:esp32 .
```

In Blynk app:
- Create a button widget mapped to `V0`
- Set mode to `Switch`
- Use values `0` and `1`

---

<p align="center">
	<img src="https://capsule-render.vercel.app/api?type=waving&color=0:FFFFFF,100:F5F5DC&height=100&section=footer"/>
</p>
