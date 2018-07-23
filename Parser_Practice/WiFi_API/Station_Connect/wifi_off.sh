#!/bin/bash
#!/bin/bash
# Program:
#       This program is used to turn on the wifi mode.
# History:
# 2018/07/4     PaulFirst release

# Turn On the Wi-Fi mode 
echo "1" > /sys/class/edm/gpio/USB_OTG2/value
# search Wi-Fi
iwlist wlx4c0fc716fbaf scan > /home/mayqueen/on_record.txt 2>&1
# remove the file wifi_home.conf
rm wifi_home.conf
# setup the ssid & password
wpa_passphrase icannottellyou_RPT 77777777 > wifi_home.conf
#!/bin/bash
# Program:
#       This program is used to turn off the wifi mode.
# History:
# 2018/07/4     PaulFirst release
# Kill the Wi-Fi Station Mode 
printf "Kill the process wpa_supplicant\n\n" > /home/mayqueen/wifi_off_record.txx
t 2>&1
#kill the process wpa_supplicant
pkill wpa_supplicant > /home/mayqueen/wifi_off_record.txt 2>&1
printf "Kill the process dhclient\n\n" > /home/mayqueen/wifi_off_record.txt 2>&1
#kill the process dhclient
pkill dhclient > /home/mayqueen/wifi_off_record.txt
printf "sned the 0 to turn off the wifi hardware\n\n" > /home/mayqueen/wifi_off__
record.txt 2>&1
# Turn off the hardware Wi-Fi
echo "0" > /sys/class/edm/gpio/USB_OTG2/value > /home/mayqueen/wifi_off_record.tt
xt 2>&1
# Delay 0.3 sec
sleep 0.3
exit 0

