from PySide6 import QtWidgets, QtSql


class Data:
    def __init__(self):
        super(Data, self).__init__()

    def create_connection(self):
        db = QtSql.QSqlDatabase.addDatabase('QSQLITE')
        db.setDatabaseName('calc3d')

        if not db.open():
            QtWidgets.QMessageBox.critical(None, 'Error', 'Не найдена база данных калькулятора',
                                           'Cancel',
                                           QtWidgets.QMessageBox.Cancel)
            return False

        query = QtSql.QSqlQuery()
        query.exec("CREATE TABLE IF NOT EXISTS printers (ID integer primary key autoincrement,"
                   "Printer_name VARCHAR(30) unique, Price_printer integer,  Printer_power integer, kilowatt_price)")
        return True

    def execute_query_with_params(self, sql_query, query_values=None):
        query = QtSql.QSqlQuery()
        query.prepare(sql_query)

        if query_values is not None:
            for value in query_values:
                query.addBindValue(query_values)
        query.exec()


    def add_settings(self, kilowatt_price, ):
        pass

    def add_printer(self, printer_name, printer_power, price_printer):
        sql_query = "INSERT INTO printers (Printer_name, Printer_power, Price_printer) VALUES (?, ?, ?)"
        self.execute_query_with_params(sql_query, [printer_name, printer_power, price_printer])

    def edit_printer(self, id, printer_name, printer_power, price_printer):
        sql_query = "UPDATE printers SET Printer_name=?, Printer_power=?, Price_printer=? WHERE ID=?"
        self.execute_query_with_params(sql_query, [id, printer_name, printer_power, price_printer])

    def delete_printer(self, id):
        sql_query = "DELETE FROM printers WHERE ID=?"
        self.execute_query_with_params(sql_query, [id])
