# main.py
import time
import requests
import serial
from requests.auth import HTTPBasicAuth

COM_PORT = 'COM9'       # Your Arduino port
PASSWORD = 'test'
VLC_URL = 'http://localhost:8080/requests/status.json'

ser = serial.Serial(COM_PORT, 9600)

def get_vlc_title():
    try:
        response = requests.get(VLC_URL, auth=HTTPBasicAuth('', PASSWORD))
        data = response.json()
        meta = data.get("information", {}).get("category", {}).get("meta", {})
        # Try title, then fallback to filename
        return meta.get("title") or meta.get("filename") or "Nothing Playing"
    except Exception as e:
        return "VLC Offline"

while True:
    title = get_vlc_title()
    print(title);
    ser.write((title + '\n').encode())
    time.sleep(1)
