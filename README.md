# buttonWork
##About
This project counts seconds of button holding. Project is designed for stm32f407vg. Button reading is debounced.

##Hardware requirements
1. USB to uart converter. Use any converter that supports 3.3v TTL. Many converters may work on 3.3v but torance to 5v. As an example may be used cp2102.
2. Board with stm32f407vg MCU (maybe discovery)
3. ST-Link programmer

##Software Requirements
1. IDE named "System workbench for STM32" or atnother eclipse ( than you need for manual toolchain pathes settings )
2. ST-link drivers
3. ST-LINK utility
4. Drivers for your ttl converter (usb to uart)

##Building
1. Open System workbench and import downloaded project into your workspace.
2. Connect MCU to computer via ST-LINK port. If you use discovery check jumpers that are located in the board, it should be shorted. 
3. Go in menu to menu -> project -> Build project
4. Press run button for flashing MCU.


##Only FLASH WITHOUT BUILDING
If you don't want compile firmware, you should have ST-link utility for flashing MCU. On stm32f407 discovery board st-link included

1. Connect MCU to computer via ST-LINK port. If you use discovery check jumpers located in the board, it should be shorted.
2. Open ST-LINK utility
3. Check MCU connection ( Target -> Connect ). Program must show information about your chip.
4. Select firmware file ( File -> Open ). Firmware file is located in RELEASE subdirectory of main project. Choose files with ".elf" , ".bin" extenshions.
5. Flashing with verification ( Target -> Program & Verify )
6. Enjoy
