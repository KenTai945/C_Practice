#!/bin/bash
# Program:
#       This program is used to turn on the wifi mode.
# History:
# 2018/07/4	PaulFirst release

# Turn On the Wi-Fi mode 
echo "1" > /sys/class/edm/gpio/USB_OTG2/value
# Check the value to confirm the Wi-Fi is on or not
cat /sys/class/edm/gpio/USB_OTG2/value
# check all the Interfce to know is it on or not
ifconfig
# search Wi-Fi
iwlist wlx4c0fc716fbaf scan
# remove the file wifi_home.conf
rm wifi_home.conf
# setup the ssid & password
wpa_passphrase icannottellyou_RPT 77777777 > wifi_home.conf
# exute the command to connect with wifi
wpa_supplicant -i wlx4c0fc716fbaf -c wifi_home.conf -Dwext &
# setup the IP
dhclient wlx4c0fc716fbaf
# check the interface again
ifconfig
exit 0
