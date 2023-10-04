import serial
import time

serial_port = '/dev/ttyACM0'
baud_rate = 9600

ser = serial.Serial(serial_port, baud_rate)

# Time to initialize
time.sleep(2)

try:
    while True:
        val = "<HIGH>"
        ser.write(val.encode())
        time.sleep(5)
        val = "<LOW>"
        ser.write(val.encode())
        time.sleep(5)
except KeyboardInterrupt:
    ser.close()
