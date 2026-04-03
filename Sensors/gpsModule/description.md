1. Antenna (Signal Catcher)
4
This is what receives signals from GPS satellites
Usually a ceramic patch antenna or small external antenna
It doesn’t send signals — only listens 📡

🧠 2. GPS Receiver Chip (The Brain)
4
This is the main component
It:
Reads signals from multiple satellites (usually 4+)
Calculates your latitude, longitude, altitude
Uses timing differences between signals to compute distance

👉 Popular chips: like the u-blox NEO-6M

⏱️ 3. Clock (Precise Timing)
GPS works using very accurate time signals
Satellites send timestamps ⏳
The module uses an internal clock (not as perfect as satellite atomic clocks but good enough)

🧮 4. Microcontroller / Processor
Processes all the math (called trilateration)
Converts raw satellite data into readable coordinates


📡 5. Communication Interface
Sends data to your device (Arduino, phone, etc.)
Common protocols:
UART (serial)
I2C / SPI
