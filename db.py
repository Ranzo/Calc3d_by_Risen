import sqlite3


def sqlite_connect():
    conn = sqlite3.connect("db/database.db", check_same_thread=False)
    conn.execute("pragma journal_mode=wal;")
    return conn


def init_sqlite():
    conn = sqlite_connect()
    cursor = conn.cursor()
    try:
        # Начинаем транзакцию
        cursor.execute('BEGIN')
        # Выполняем операции
        cursor.execute('''CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            tg_id INTEGER NOT NULL UNIQUE ,
            school_nik TEXT NOT NULL UNIQUE,
            username TEXT UNIQUE,
            number_quest INTEGER,
            city TEXT)''')

        cursor.execute('''CREATE INDEX IF NOT EXISTS usrid ON users (number_quest)''')

        cursor.execute('''CREATE TABLE IF NOT EXISTS flags (
            id INTEGER PRIMARY KEY AUTOINCREMENT,        
            flags TEXT NOT NULL UNIQUE)''')

        cursor.execute('''CREATE TABLE IF NOT EXISTS token (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,        
                    token TEXT NOT NULL UNIQUE)''')
        cursor.execute('COMMIT')
    except Exception as e:
        print(e)
        cursor.execute('ROLLBACK')
    conn.close()

def registration(user_id, school_nik, uname, number_quest, city, class_name, end_14):
    conn = sqlite_connect()
    cursor = conn.cursor()
    try:
        cursor.execute('BEGIN')
        cursor.execute('INSERT INTO users (tg_id, school_nik, username, number_quest, city, class_name, end_14)'
                       ' VALUES (?, ?, ?, ?, ?, ?, ?)',
                       (user_id, school_nik, uname, number_quest, city, class_name, end_14))
        cursor.execute('COMMIT')
    except Exception as e:
        print(e)
        cursor.execute('ROLLBACK')
    conn.close()


def quest_1(tg_id, date_begin):
    conn = sqlite_connect()
    cursor = conn.cursor()
    try:
        cursor.execute('BEGIN')
        cursor.execute(f'UPDATE users SET date_begin=(?) WHERE tg_id=(?)', (date_begin, tg_id,))
        cursor.execute('COMMIT')
    except Exception as e:
        print(e)
        cursor.execute('ROLLBACK')
    conn.close()

def get_time(username):
    conn = sqlite_connect()
    cursor = conn.cursor()
    try:
        cursor.execute('BEGIN')
        time = cursor.execute('SELECT date_begin, end_13 FROM users WHERE school_nik = (?)', (username,)).fetchone()
        return time
    except Exception as e:
        print(e)
        cursor.execute('ROLLBACK')
    conn.close()

