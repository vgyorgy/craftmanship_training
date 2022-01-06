# for window GUI:
#     sudo apt install libgtk-3-dev libgtkmm-3.0-dev
# for SQLite3 database:
#     sudo apt-get install libsqlite3-dev

# GUI source:
GUI_SOURCE_1=gui_1.cpp
GUI_SOURCE_2=gui_2.cpp

# GUI configuration:
GUI_CONFIG_1=
GUI_CONFIG_2=`pkg-config --cflags --libs gtkmm-3.0`

# Persistent source:
PERSISTENT_1=persistent_1.cpp
PERSISTENT_2=persistent_2.cpp

# Persistent configuration:
PERSISTENT_CONFIG_1=
PERSISTENT_CONFIG_2=-l sqlite3

# Common sources (4 options):
COMMON_SOURCES=business_rule.cpp car.cpp $(GUI_SOURCE_1) $(GUI_CONFIG_1) $(PERSISTENT_1) $(PERSISTENT_CONFIG_1)
# COMMON_SOURCES=business_rule.cpp car.cpp $(GUI_SOURCE_2) $(GUI_CONFIG_2) $(PERSISTENT_1) $(PERSISTENT_CONFIG_1)
# COMMON_SOURCES=business_rule.cpp car.cpp $(GUI_SOURCE_1) $(GUI_CONFIG_1) $(PERSISTENT_2) $(PERSISTENT_CONFIG_2)
# COMMON_SOURCES=business_rule.cpp car.cpp $(GUI_SOURCE_2) $(GUI_CONFIG_2) $(PERSISTENT_2) $(PERSISTENT_CONFIG_2)

# Targets:
starter: $(STARTER_SOURCES)
	g++ starter.cpp $(COMMON_SOURCES) -I. -o starter

test_persistent:
	g++ test_persistent.cpp $(COMMON_SOURCES) -I. -o test_persistent

clean:
	rm -f starter
	rm -f test_persistent
	rm -f db.txt
	rm -f db.sql
