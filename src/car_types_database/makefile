# linker error when using "gcc" : https://stackoverflow.com/questions/20010244/undefined-reference-to-stdios-baseinitinit
# for window GUI: sudo apt install libgtk-3-dev libgtkmm-3.0-dev

# GUI sources:
GUI_SOURCE_1=gui_1.cpp
GUI_SOURCE_2=gui_2.cpp
SELECTED_GUI_SOURCE=$(GUI_SOURCE_1)

# GUI configuration:
GUI_CONFIG_1=
GUI_CONFIG_2=`pkg-config --cflags --libs gtkmm-3.0`
SELECTED_GUI_CONFIG=$(GUI_CONFIG_1)

# Persistent module configuration:
PERSISTENT_1=persistent_1.cpp
PERSISTENT_2=persistent_2.cpp
SELECTED_PERSISTENT=$(PERSISTENT_1)

# Collected sources:
STARTER_SOURCES=starter.cpp business_rule.cpp $(SELECTED_GUI_SOURCE) $(SELECTED_PERSISTENT) car.cpp
TEST_PERSISTENT_SOURCES=test_persistent.cpp business_rule.cpp $(SELECTED_GUI_SOURCE) $(SELECTED_PERSISTENT) car.cpp

# Targets:
starter: $(STARTER_SOURCES)
	rm -f starter
	g++ $(STARTER_SOURCES) $(SELECTED_GUI_CONFIG) -I. -o starter

test_persistent:
	g++ $(TEST_PERSISTENT_SOURCES) $(SELECTED_GUI_CONFIG) -I. -o test_persistent
