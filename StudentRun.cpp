// StudentRun.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

//assigning types to all the variables used throughout the code
string user_type, user_name, username, password;
string logindata, account_check;
string job_choice, job_day, job_time;
string timeOfJob;
string employeeChosen;
string chosenDay, chosenTime;
string CalFileName, ItinFileName;
string full_name, address;
string make_account, account_details;

int user_choice, contact_number, employee_choice;

bool valid_input = false;
bool valid2_input = false;

//reducing magic numbers
const int MAXACCOUNTS = 3;

struct job_details {

	string job_choice;
	string timeOfJob;
	string job_day;

};


struct customerInfo {

	string username;
	string password;
	string fullName;
	string Address;
	int contactNumber;
};


//creating an object for this class
job_details newJob;


//creating an object for this class
customerInfo newCustomer;


//determining whether the user is an employee or cutomer
//returning user_type to be used later in program to run specific sets of code
string getusertype()
{

	cout << "Are you an employee or a customer?" << endl;
	cin >> user_type;

	//validating user input
	if ((user_type == "employee") || (user_type == "customer"))
	{
		valid_input = true;
	}



	while (valid_input == false)
	{
		cout << "Invalid Input. Please re-enter a valid input: " << endl;
		cin >> user_type;
		if ((user_type == "employee") || (user_type == "customer"))
		{
			valid_input = true;
		}

	}

	return user_type;
}

//if the user is an employee then this section of code will run
//allows the employee to enter username and password, then it is checked to see
//if it matches the array


//determining is the customer has an account
//returning account_check to run different parts of code later on
string customeraccount()
{
	cout << "Hello New Customer!" << endl;
	cout << "Do you have an account?" << endl;
	cin >> account_check;

	if ((account_check == "yes") || (account_check == "no"))
	{
		cout << "Thank you" << endl;
	}
	else
	{
		cout << "Please enter a valid answer: " << endl;
		cin >> account_check;
	} 
	return account_check;
}


//creating a function of class customerInfo to return struct
//uses the object newCustomer to add values to the struct
//returns the struct to be used later in code
customerInfo customerlogin()
{
	cout << "Enter your username" << endl;
	cin >> newCustomer.username;
	cout << "Enter your password" << endl;
	cin >> newCustomer.password;

	return newCustomer;
}

//checking the customer username and password
//against text file containing customer accounts
void openCustomerAcc()
{
	//initialising blank line to search through file
	string line;

	//opening the text file
	ifstream inFile;
	inFile.open("customeraccounts.txt");

	//error catch if the program cannot open the file
	if (!inFile)
	{
		cout << "Oh dear, your file is not here" << endl;
		exit(1);
	}

	else
	{
		//while not at the end of the file
		//searching through the file until the end is reached
		while (!inFile.eof())
		{
			//getline function reads a string from a text file
			//line is where the string we are looking for is stored
			getline(inFile, line);

			//string the program needs to find
			if (line == (newCustomer.username + " " + newCustomer.password))
			{
				cout << "Account Found. You are now logged in." << endl;
				break; //breaks the loop and moves onto the next function
			}

			else
			{
				cout << "";
			}

		}

		//if the string cannot be found, no account exists
		if (line != (newCustomer.username + " " + newCustomer.password))
		{
			cout << "Log in unsuccesful. You can continue as a guest." << endl;
		}

		//closing the text file so next time it is opened
		//cursor is at the top and search starts from the top
		inFile.close();

	}
}

//funtion to output information to a customer without an account
void newcustomer()
{
	cout << "Welcome Guest!" << endl;
	cout << "You will have the chance to create an account at the end of your booking if you would like to." << endl;
	cout << "But for now lets continue with your booking!" << endl;
}

//function displaying the jobs that the customers can choose from, or log out
void displayjobs()
{
	cout << "Below are the jobs that CED property Services Ltd. offer:" << endl;
	cout << "1. Home Buyers Condition Survey" << endl << "2. Domestic EPC" << endl << "3. Commerical EPC" << endl
		<< "4. Property Inventory for Landlords" << endl << "5. Floorplans" << endl << "6. Log out" << endl;

}

//determining which job the user wants to choose
//returning user_choice to be used later in code
int getuserchoice()
{
	cout << "Please enter the number of the service you would like to choose:" << endl;
	cin >> user_choice;
	
	if ((user_choice < 0) || (user_choice > 7) || (user_choice == 0))
	{
		cout << "Invalid input. Please choose another option: " << endl;
		cin >> user_choice;
	}
	return user_choice;
}


//function of a class
//adding job choice to the object of the class
//not adding job_time to object as it is not needed later in code
job_details jobchoice(int user_choice)
{

	switch (user_choice)
	{
	case 1:
		newJob.job_choice = "Home Buyers Condition Survey";
		job_time = "two";
		break;
	case 2:
		newJob.job_choice = "Domestic EPC";
		job_time = "one";
		break;
	case 3:
		newJob.job_choice = "Commerical EPC";
		job_time = "two";
		break;
	case 4:
		newJob.job_choice = "Property Inventory for Landlords";
		job_time = "one";
		break;
	case 5:
		newJob.job_choice = "Floorplans";
		job_time = "one";
		break;
	case 6:
		break; //Add log out function when created

	//error catch	  
	default:
		break;

	}

	cout << "Thank you for choosing " << newJob.job_choice << endl;
	cout << "This will take approximately " << job_time << " hours" << endl;
	cout << "Now lets choose an employee to do the job!" << endl;

	//returning object of class for data to be used later
	return newJob;
}

//displaying which employees are available for certain jobs
//using a switch statement to make code more succinct
string chooseEmployee(job_details newJob, int user_choice)
{
	cout << "As you have chosen " << newJob.job_choice << " the employees available for this are:" << endl;

	switch (user_choice)
	{
	case 1:
		cout << "Chris, Steve" << endl;
		break;

	case 2:
		cout << "Chris, Steve, Mark" << endl;
		break;

	case 3:
		cout << "Chris, Steve, Mark" << endl;
		break;

	case 4:
		cout << "Chris" << endl;
		break;

	case 5:
		cout << "Chris, Steve, Mark" << endl;
		break;

	case 6:
		break;

	default:
		break;
	}

	cout << "Please enter the employee you would like and then their availability will show: " << endl;
	cin >> employeeChosen;

	switch (user_choice)
	{
	case 1:
		if ((employeeChosen == "Chris") || (employeeChosen == "Steve"))
		{
			break;
		}
		else
		{
			cout << "Invalid choice. Please enter a valid employee: " << endl;
			cin >> employeeChosen;
		}
		break;

	case 2: case 3: case 5:
		if ((employeeChosen == "Chris") || (employeeChosen == "Steve") || (employeeChosen == "Mark"))
		{
			break;
		}
		else
		{
			cout << "Invalid choice. Please enter a valid employee: " << endl;
			cin >> employeeChosen;
		}
		break;

	case 4:
		if (employeeChosen == "Chris")
		{
			break;
		}
		else
		{
			cout << "Invalid choice. Please enter a valid employee: " << endl;
			cin >> employeeChosen;
		}
	default:
		break;
	}


	//returning employeeChosen to be used later in code
	return employeeChosen;

}

//displaying the availability of the employee that has been chosen
void displayCalendar(string employeeChosen)
{

	//initialising line to search through file
	string line;
	cout << "You have chosen " << employeeChosen << " to complete your job." << endl;
	cout << "This is their availability: " << endl;

	//creating the name of the file which needs to be opened
	CalFileName = employeeChosen + "Calendar.txt";

	//opening file
	ifstream inFile;
	inFile.open(CalFileName);

	//error catch if the file cannot be opened
	if (!inFile)
	{
		cout << "Oh dear, your file is not here" << endl;
		exit(1);
	}

	else
	{
		//while not at the end of the file
		while (!inFile.eof())
		{
			//reading every line of the text file
			//line is where the string we are looking for is stored
			//outputting line every time so every line is displayed
			getline(inFile, line);
			cout << line << endl;
		}

		//closing the text file
		inFile.close();


	}

}

//function of a class job_details
//returns an object of the class to
//be used later on in the code
// add user faulty input catch
job_details getDate(string employeeChosen)
{
	string line;

	cout << "Please enter the day you would like to book: " << endl;
	cin >> newJob.job_day;
	cout << "Please enter the time you would like to book: " << endl;
	cin >> newJob.timeOfJob;



	return newJob;
}

//booking the job by removing the availability
//from the employees calendar
//no other customer will be able to see that time slot
void bookJob(job_details newJob, string CalFileName)
{

	//initialising blank line to search through text file
	string line;
	cout << "You would like to book your job for " << newJob.job_day << " at " << newJob.timeOfJob << endl;

	//opening the text file
	ifstream inFile;
	inFile.open(CalFileName);

	//error catch if text file cannot be opened
	if (!inFile)
	{
		cout << "File cannot be found" << endl;
	}


	while (!inFile.eof())
	{
		//getline function reads a string from a text file
		//line is where the string we are looking for is stored
		getline(inFile, line);

		//string the program needs to find
		if (line == (newJob.job_day + " " + newJob.timeOfJob))
		{
			break; //breaks the loop and moves onto the next function
		}

		else
		{
			cout << "";
		}

	}

	//if the string cannot be found, no account exists
	if (line != (newJob.job_day + " " + newJob.timeOfJob))
	{
		cout << "Day and time unavailable. Please re-enter a valid day: " << endl;
		cin >> newJob.job_day;
		cout << "Please re-enter a valid corresponding time: " << endl;
		cin >> newJob.timeOfJob;
	}


	
	//opening the text file the code will output to
	ofstream temp;
	temp.open("temp.txt");

	
	//searching through the text file for the string
	//matching the day and time customer has chosen
	//line is where the string we are looking for is stored - old contents replaced every time
	while (getline(inFile, line))
	{
		if (line != (newJob.job_day + " " + newJob.timeOfJob))
		{
			//outputting every line that does not match that to
			//a temporary file
			temp << line << endl;
		}
	}

	//closing both files
	temp.close();
	inFile.close();

	//opening the correct text file dependant
	//on the employee
	//removing the old version of the file and
	//renaming the temporary file with a new name
	//this updates the availability that is shown to other customers
	if (employeeChosen == "Chris")
	{
		remove("ChrisCalendar.txt");
		rename("temp.txt", "ChrisCalendar.txt");
	}

	else if (employeeChosen == "Steve")
	{
		remove("SteveCalendar.txt");
		rename("temp.txt", "SteveCalendar.txt");
	}

	else if (employeeChosen == "Mark")
	{
		remove("MarkCalendar.txt");
		rename("temp.txt", "MarkCalendar.txt");
	}

	cout << "The booking has been reserved!" << endl;


}

//function of a class
//returns object of that class to be used later
//in program
customerInfo addDetails()
{

	//adding values to the object
	cout << "Now that your booking has been reserved we need some extra details to confirm the booking." << endl;
	cout << "Please enter your first name: " << endl;
	cin >> newCustomer.fullName;
	cout << "Please enter your postcode without spaces: " << endl;
	cin >> newCustomer.Address;
	cout << "Please enter your mobile number with no spaces: " << endl;
	cin >> newCustomer.contactNumber;

	cout << "Thank you! You have now made your booking!" << endl;
	cout << "Our employee will contact you when they are on the way." << endl;



	return newCustomer;
}

//adding job details to the itinerary calendar for specified employee
void itinJob(string employeeChosen, customerInfo newCustomer, job_details newJob)
{

	//creating file name for correct employee
	ItinFileName = employeeChosen + "Itinerary.txt";

	//opening the text file to output details to
	ofstream inFile;
	inFile.open(ItinFileName);

	//adding those details to the text file
	inFile << newCustomer.fullName << " ";
	inFile << newCustomer.Address << " ";
	inFile << newCustomer.contactNumber << " ";
	inFile << newJob.job_choice;

	//closing text file
	inFile.close();

}


//displaying the options that the employees have
void employeeOptions()
{
	cout << "Thank you for logging in." << endl;
	cout << "These are the services you have access to: " << endl;
	cout << "1. View Itinerary" << endl << "2. Log Out" << endl;
}

//determining which option the employee wants to choose
//returning employee_choice to use later in code to
//display correct section of code
int employeeChoice()
{
	cout << "Enter the number of the service you'd like to choose: " << endl;
	cin >> employee_choice;

	if ((employee_choice < 0) || (employee_choice > 3))
	{
		cout << "Invalid input. Please choose another option: " << endl;
		cin >> employee_choice;
	}


	return employee_choice;
}


//displaying the employees itinerary (e.g. jobs booked)
//can only view their own itinerary
void viewItinerary()
{

	//opening the correct itinerary
	string UserName;
	cout << "Please re-enter your username: " << endl;
	cin >> UserName;
	//initilising blank line to search through text file
	string line;

	//creating file name so that only the employee can view their own itinerary
	ItinFileName = UserName + "Itinerary.txt";

	//opening text file
	ifstream inFile;
	inFile.open(ItinFileName);

	//error catch if text file cannot be opened
	if (!inFile)
	{
		cout << "File not available to view" << endl;
		exit(1);
	}

	else
	{
		//while not at the end of the file
		//keep searching through until end is reached
		while (!inFile.eof())
		{
			//getline function searches for strings in a text file
			//line is where the string we are looking for is stored - old contents replaced every time
			getline(inFile, line);

			//line displayed every time
			//so every line of file displayed
			//employee can view their whole itinerary
			cout << line << endl;
		}

		//closing file so when re-opened it returns
		//to the top
		inFile.close();


	}

}

void createAccount()
{
	string line;
	cout << "Before leaving, would you like to create an account on our system?" << endl;
	cin >> make_account;

	if (make_account == "yes")
	{
		cout << "Please enter a username: " << endl;
		cin >> username;

		cout << "Please enter a password: " << endl;
		cin >> password;

		account_details = username + " " + password;

		ifstream inFile;
		inFile.open("customeraccounts.txt");

		ofstream temp;
		temp.open("temp.txt");

		while (getline(inFile, line))
		{
			if (line != (account_details))
			{
				temp << line << endl;
			}
		}

		temp.close();
		inFile.close();

		remove("customeraccounts.txt");
		rename("temp.txt", "customeraccounts.txt");

		cout << "Account made. Thank you." << endl;

	}
	
	else
	{
		cout << "Okay. Thank you." << endl;
	}
}

//log out function used at the end of the program when services are completed
//or if the employee or customer chooses to logout
void logOut()
{
	cout << "Thank you for using the CED Property Services Ltd. booking system." << endl;
	cout << "Goodbye." << endl;
	exit(0);
}



int main()
{
	
	getusertype();

	//assigning usertype the returned value user_type
	//determines which section of code will run
	string usertype = user_type;

	//employee section of code
	if (usertype == "employee")
	{
		employee myobject;
		myobject.employeelogin();
		user_name = myobject.username;

		//if the account cannot be found
		//employee automatically denied access
		//program ends
		if (user_name == "Access Denied")
		{
			logOut();
		}

		//if the account can be found the program
		//continues as normal
		else
		{
			employeeOptions();
			employeeChoice();

			//assigning emp_choice the returned value of employee_choice
			//determines which function will run
			int emp_choice = employee_choice;
			if (emp_choice == 1)
			{
				viewItinerary();
			}

			else if (emp_choice == 2)
			{
				logOut();
			}

		}
	}


	//customer sections of code
	else if (usertype == "customer")
	{
		customeraccount();

		//assigning accountcheck returned value of account_check
		//determines which sections of code will run
		string accountcheck = account_check;

		//if the user does have an account
		if (accountcheck == "yes")
		{
			cout << "lets check your account" << endl;

			//functions run to check if the account exists
			customerlogin();
			openCustomerAcc();
		}

		else
		{
			newcustomer();

		}

		//functions run whether the customer has an account or not
		displayjobs();
		getuserchoice();

		//userChoise assigned returned value of user_choice
		//determines which function will run
		int userChoice = user_choice;

		//if the customer chooses to logout
		if (userChoice == 6)
		{
			logOut();
		}

		//customer chooses any of the other options
		//these functions run to book the job etc.
		else
		{
			jobchoice(user_choice);
			chooseEmployee(newJob, user_choice);
			displayCalendar(employeeChosen);
			getDate(employeeChosen);
			bookJob(newJob, CalFileName);
			addDetails();
			itinJob(employeeChosen, newCustomer, newJob);

			if (accountcheck == "no")
			{
				createAccount();
				logOut();
			}
			
			else
			{
				logOut();
			}
		}

	}

	return 0;

}
