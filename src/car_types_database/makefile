# linker error when using "gcc" : https://stackoverflow.com/questions/20010244/undefined-reference-to-stdios-baseinitinit
# for window GUI: sudo apt install libgtk-3-dev libgtkmm-3.0-dev

# GUI configuration:
GUI_1="gui_1.cpp"                                           # console output
GUI_2="gui_2.cpp" `pkg-config --cflags --libs gtkmm-3.0`    # window application

# Targets:
all: starter.cpp business_rule.cpp
	rm -f starter
	g++ starter.cpp business_rule.cpp $(GUI_2) -I. -o starter

