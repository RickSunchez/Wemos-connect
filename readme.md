# lab

1. настройте Arduino IDE: [например тут](https://habr.com/ru/post/371853/)
2. скопируйте код
3. запустите точку доступа Wi-Fi на телефоне
4. измените в коде строчки для подключения к вашему Wi-Fi:

```c++
    const char* ssid = "YOUR_WIFI_SSID(name)";
    const char* password = "YOUT_WIFI_PASSWORD";
```

5. загрузите код
6. откройте монитор порта в Arduino IDE
7. установите скорость работы на 115200 бод
8. перезапустите плату
9. в монитор порта выведется IP-адрес для подключения к плате, в браузере телефона перейдите по этому адресу, добавьте к нему "/sayhello"
10. подключите к плате светодиод к пину D4
11. перейдите по адресу "/led/on" для включения светодиода и по адресу "/led/off" для выключения
12. подключите второй светодиод, внимательно изучите [схему](https://ae01.alicdn.com/kf/H5d6583ae94e34373a3e673991f353ba6F.jpg) и нумерацию пинов
13. пропишите свои адреса для включения и выключения второго светодиода
14. добавьте адреса для включения и выключения обоих светодиодов
15. добавьте адрес, по которому светодиоды начнут попеременно моргать