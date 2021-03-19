This directory contains the updated files if you are using the older Wireless Named Data Networking repository and directory. 
ONLY FOLLOW THESE INSTRUCTIONS IF YOU ARE USING THE OLDER DIRECTORY!

Here are the instructions to install the files:
Go to the main directory:
```
cd ~
```

Then grab the full NDN repository:
```
sudo git clone --recursive https://github.com/Jiuro/NDN_over_LoRa.git
```

Next:
```
cd ~/NDN_over_LoRa/Wireless-Named-Data-Networking-over-LoRa
```

Now copy the files to the correct locations:
```
sudo cp -r arduPiLoRa.cpp ~/Wireless-Named-Data-Networking-over-LoRa/NFD/lora_libs/libraries/arduPiLoRa
sudo cp -r arduPiLoRa.h ~/Wireless-Named-Data-Networking-over-LoRa/NFD/lora_libs/libraries/arduPiLoRa
sudo cp -r lora-factory.cpp ~/Wireless-Named-Data-Networking-over-LoRa/NFD/daemon/face
sudo cp -r test ~/Wireless-Named-Data-Networking-over-LoRa/NFD/lora_libs
sudo cp -r setup ~/Wireless-Named-Data-Networking-over-LoRa/NFD/lora_libs
```

Then go back to the main instructions and compile the NFD directory and the LoRa Configuration.

If you wish to delete this folder, as it will no longer be used, use the following:
```
cd ~
sudo rm NDN_over_LoRa
```
