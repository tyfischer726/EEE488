# EEE488
In the ESP8266 directory, the following files must be updated:
  - arduino_secrets.h, all variables
  - thingProperties.h, only DEVICE_LOGIN_NAME
  - Note: The SECRET_DEVICE_KEY (arduino_secrets.h) and the DEVICE_LOGIN_NAME (thingProperties.h)
    are obtained by navigating to the Arduino Cloud and adding a device and generating a secret key
