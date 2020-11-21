#ifndef _HISTORY_TRANSACTION_CPP_
#define _HISTORY_TRANSACTION_CPP_

#include <cassert>
#include <iomanip>
#include <iostream>

#include "project4.hpp"
#include "History.hpp"
#include "Transaction.hpp"

/*
int main() {
	std::cout << "HI";
	return 0;
}*/

////////////////////////////////////////////////////////////////////////////////
// Definitions for Transaction class
////////////////////////////////////////////////////////////////////////////////
//
//

// Constructor
// TASK 1
//

Transaction::Transaction(std::string ticker_symbol, unsigned int day_date, unsigned int month_date, unsigned year_date, bool buy_sell_trans, unsigned int number_shares, double trans_amount) {
	return;
}


// Destructor
// TASK 1
//
Transaction::~Transaction() {
	return;
}

// Overloaded < operator.
// TASK 2
//
bool Transaction::operator<(Transaction const &other) {
	return 0;
}


// GIVEN
// Member functions to get values.
//
std::string Transaction::get_symbol() const { return symbol; }
unsigned int Transaction::get_day() const { return day; }
unsigned int Transaction::get_month() const { return month; }
unsigned int Transaction::get_year() const { return year; }
unsigned int Transaction::get_shares() const { return shares; }
double Transaction::get_amount() const { return amount; }
double Transaction::get_acb() const { return acb; }
double Transaction::get_acb_per_share() const { return acb_per_share; }
unsigned int Transaction::get_share_balance() const { return share_balance; }
double Transaction::get_cgl() const { return cgl; }
bool Transaction::get_trans_type() const { return (trans_type == "Buy") ? true: false ; }
unsigned int Transaction::get_trans_id() const { return trans_id; }
Transaction *Transaction::get_next() { return p_next; }

// GIVEN
// Member functions to set values.
//
void Transaction::set_acb( double acb_value ) { acb = acb_value; }
void Transaction::set_acb_per_share( double acb_share_value ) { acb_per_share = acb_share_value; }
void Transaction::set_share_balance( unsigned int bal ) { share_balance = bal ; }
void Transaction::set_cgl( double value ) { cgl = value; }
void Transaction::set_next( Transaction *p_new_next ) { p_next = p_new_next; }

// GIVEN
// Print the transaction.
//
void Transaction::print() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(4) << get_trans_id() << " "
    << std::setw(4) << get_symbol() << " "
    << std::setw(4) << get_day() << " "
    << std::setw(4) << get_month() << " "
    << std::setw(4) << get_year() << " ";


  if ( get_trans_type() ) {
    std::cout << "  Buy  ";
  } else { std::cout << "  Sell "; }

  std::cout << std::setw(4) << get_shares() << " "
    << std::setw(10) << get_amount() << " "
    << std::setw(10) << get_acb() << " " << std::setw(4) << get_share_balance() << " "
    << std::setw(10) << std::setprecision(3) << get_acb_per_share() << " "
    << std::setw(10) << std::setprecision(3) << get_cgl()
    << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// Definitions for the History class
////////////////////////////////////////////////////////////////////////////////
//
//


// Constructor - function that automatically gets called when an object is CREATED / INSTANTIATED
// TASK 3
//
History::History() {
	p_head = nullptr;
	}
	//set p_next to NULL (so that it is closed loop with appending)

// Destructor - a function that automatically gets called when an object is DEALLOCATED
// we need to deallocate all of the dynamically allocated memory
// TASK 3
//

History::~History() {

	Transaction * p_traverse {p_head};

	while (p_head != nullptr)  {
		p_traverse = p_head;
		p_head = p_head->get_next();

		delete p_traverse;
		p_traverse = nullptr;
	}
}

// read_transaction(...): Read the transaction history from file - make it into a Transaction instance and INSERT it into the linked list
// TASK 4
//
void History::read_history() {
	ece150::open_file();

	while(ece150::next_trans_entry()) { //iterates through all of the entries until it reaches the last line (EOF)
		std::string symbol = ece150::get_trans_symbol();
		unsigned int day {ece150::get_trans_day()};
		unsigned int month {ece150::get_trans_month()};
		unsigned int year {ece150::get_trans_year()};
		unsigned int shares {ece150::get_trans_shares()};
		bool type {ece150::get_trans_type()};
		double amount {ece150::get_trans_amount()};

		std::cout << symbol << " " << day << " " << month << " " << year << " " << type << " " << shares << " " << amount << std::endl;
	}

	ece150::close_file();
	return;
}
// insert(...): Insert transaction into linked list.
// TASK 5
//
void History::insert (Transaction * p_new_trans) { //ALI IN BR 6 - BASICALLY APPENDING STUFF + also count the assigned_trans_id s to keep an idea of how many instances of the Transaction class you have


	//PRINCE ALI !!

	if (p_head == nullptr) {
		//empty case (set p_head to this new guy)
		p_head = p_new_trans;
	}

	else {
		//if there already exists some elements in the list, find the last entry and add this new transaction to the next
		Transaction * p_traverse {p_head};
		while(p_traverse->get_next() != nullptr) {
			p_traverse = p_traverse->get_next();
		}
		p_traverse->set_next(p_new_trans);
		return;
	}
}


// sort_by_date(): Sort the linked list by trade date. - if they have same date then sort ascending trans_id
//SO BASICALLY! remove T[0], reconnect list to T[1] becomes T[0] and sizeof(T) = N-1, insert T[0] to correct spot, repeat
// TASK 6
//
void History::sort_by_date() {
	return;
}


// update_acb_cgl(): Updates the ACB and CGL values. - calculate acb, acb_per_share, share_balance, cgl for all instances
// TASK 7
//

void History::update_acb_cgl() {
	return;
}



// compute_cgl(): )Compute the ACB, and CGL. - calculate CGL for the given year (provided as a parameter)
// TASK 8

double History::compute_cgl(unsigned int year) {
	return 0;
}



// print() Print the transaction history. - basically sample output
//TASK 9
//

void History::print() {
	return;
}


// GIVEN
// get_p_head(): Full access to the linked list.
//
Transaction *History::get_p_head() { return p_head; }


#endif
