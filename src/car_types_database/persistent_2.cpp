#include <string>
#include <string.h>
#include <sqlite3.h>
using namespace std;

#include "car.h"
#include "persistent.h"
#include "business_rule.h"

#define DB_FILE             "db.sql"
#define MAX_QUERY_LENGTH    1000

static void prepare_db_if_not_prepared(void)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    static bool prepared = false;
    
    if (prepared == false)
    {
        rc = sqlite3_open(DB_FILE, &db);
        
        if (rc)
        {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
            exit(0);
        }
        else // Opened database successfully.
        {
            char sql[] = "CREATE TABLE IF NOT EXISTS cars" \
                         "(" \
                         "    manufacturer      TEXT  NOT NULL," \
                         "    type              TEXT  NOT NULL," \
                         "    subtype           TEXT  NOT NULL," \
                         "    production_start  INT," \
                         "    production_stop   INT," \
                         "    UNIQUE(manufacturer, type, subtype)" \
                         ");";
            // "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT"  // unnecessary
            rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
        }
        
        sqlite3_close(db);
        prepared = true;
    }
}

static void query(
    string sql, 
    int(* callback)(void *NotUsed, int argc, char **argv, char **azColName))
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    
    prepare_db_if_not_prepared();
    rc = sqlite3_open(DB_FILE, &db);
        
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }
    else // Opened database successfully.
    {
        // printf("Query: %s\n", sql.c_str());
        rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    }
    sqlite3_close(db);
}

void add_car(Car car)
{
    string sql = "INSERT INTO cars"
                 "("
                 "    manufacturer,"
                 "    type,"
                 "    subtype,"
                 "    production_start,"
                 "    production_stop"
                 ") "
                 "VALUES"
                 "("
                 "    '" + car.manufacturer + "', "
                 "    '" + car.type + "', "
                 "    '" + car.subtype + "', "
                 "     " + to_string(car.production_start) + ", "
                 "     " + to_string(car.production_stop) +
                 ");";
    query(sql, NULL);
}

void remove_car(Car car)
{
    string sql = "DELETE "
                 "FROM cars "
                 "WHERE       manufacturer = '" + car.manufacturer + "' "
                 "AND         type         = '" + car.type + "' "
                 "AND         subtype      = '" + car.subtype + "';";
    query(sql, NULL);
}

static bool car_stored = false;
static int is_car_stored_callback(
    void *NotUsed,
    int argc,
    char **argv,
    char **azColName)   // sql calls this for every line of result
{
    car_stored = false;
    
    if (azColName != NULL && 
        azColName[0] != NULL && 
        strcmp(azColName[0], "num_of_cars") == 0 &&
        argv[0] &&
        strcmp(argv[0], "1") == 0)
    {
        car_stored = true;
    }
    
    return(0);
}

bool is_car_stored(Car car)
{
    string sql = "SELECT count(*) AS num_of_cars "
                 "FROM   cars "
                 "WHERE  manufacturer = '" + car.manufacturer + "' "
                 "AND    type         = '" + car.type + "' "
                 "AND    subtype      = '" + car.subtype + "';";
    query(sql, is_car_stored_callback);
    return(car_stored);
}

static string cars_from_manufacturer = "";
static int get_cars_from_manufacturer_callback(
    void *NotUsed,
    int argc,
    char **argv,
    char **azColName)   // sql calls this for every line of result
{
    int i;
    string line = "";
    for(i = 0; i<argc; i++)
    {
        line += (line != "" ? "|" : "");
        line += (argv[i] ? argv[i] : "NULL");
    }
    line += '\n';
    cars_from_manufacturer += line;
    return(0);
}

string get_cars_from_manufacturer(string manufacturer)
{
    string sql = "SELECT * FROM cars WHERE manufacturer = '" + manufacturer + "';";
    cars_from_manufacturer = "";
    query(sql, get_cars_from_manufacturer_callback);
    return(cars_from_manufacturer);
}
