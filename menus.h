#ifndef MENUS_H
#define MENUS_H

#define LOGS_FILE           "logs.txt"
#define CLIENTES_DB_FILE    "clientes.bin"
#define RESERVAS_DB_FILE    "reservas.bin"

#define MAIN_MENU "\nChoose Profile\n 1 - Admin\n 2 - User\n 3 - Companies\n 0 - Quit\n Option: "
#define INVALID_OPTION "Error: Invalid option.\n"
#define ADMIN_MENU "\n PROFILE ADMIN\n 1 - Companies Management\n 2 - Branches Management\n 3 - View Reports\n 0 - Back\nOption: "
#define CLIENTES_MENU "\n PROFILE USER\n 1 - Search company by number \n 2 - Search company by nif \n 3 - Search company by location \n 4 - Classify Companies \n 5 - Comment Companies\n 0 - Back\nOption: "
#define MAX_VERIFY_CHARS 100
#define MSG_ERROR_MESSAGE "\nError"

#include "structs.h"

/**
 * @brief 
 * @param msg A custom message to prompt the user for input.
 * @param min The minimum valid integer value.
 * @param max The maximum valid integer value.
 * @return The user-provided menu.
 */
int menu(char *msg, int min, int max);

/**
 * @brief This function shows the options to choose between user and administrator.
 * @param companies A pointer to the main variable "companies" that is used to
 * pass the address of the Companies structure to subsequent functions.
 * @return This function does not return a value. It only shows the options.
 */
void mainMenu(Clientes *clientes);

/**
 * @brief This function shows the managing options to the administrator.
 * @param companies A pointer to the main variable "companies" that is used to
 * pass the address of the Companies structure to subsequent functions.
 * @return This function does not return a value. It guides the administrator
 * through the main menu options and redirects to the corresponding
 * functions based on their choices.
 */
void adminMenu(Clientes *clientes);

/**
 * @brief This function show the companies catalogs management options to the administrator.
 * @param companies the companies array where the information about the companies
 *  will be managed.
 * @return This function does not return a value. It guides the administrator 
 * through the catalogs management process and redirects to the corresponding 
 * actions based on their choices.
 */
void manageEquipamento(Clientes *clientes);


/**
 * @brief This function shows sereval options to the user to choose.
 * @param companies A pointer to the main variable "companies" that is used to
 * pass the address of the Companies structure to subsequent functions.
 * @return This function does not return a value. It guides the user through the 
 * main menu options and redirects to the corresponding functions based on their
 * choices.  
 */
void clientesMenu(Clientes *clientes);

/**
 * @brief This function allows the user to find companies.
 * @param companies The companies array where is containing information about
 * the companies in the system.
 * @return This function does not return a value. It guides the user through
 * the company search options and displays the results based on their specified
 * criteria.
 */
void searchClientes(Clientes clientes);

/**
 * @brief This function shows sereval options to the company to choose.
 * @param companies A pointer to the main variable "companies" that is used to
 * pass the adress of Companies structure to subsequent functions.
 * @return This function does not return a value. It guides the company through 
 * the main menu options and redirects to the corresponding functions based on 
 * their choices. 
 */
void espacoMenu(Clientes *clientes);

#endif /* MENU_H */

#endif