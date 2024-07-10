////////////////////////////////////////////////
// Created By: Fabert O. Charles
// File: List ADT Function Declarations
///////////////////////////////////////////////
#ifndef LIST_H
#define LIST_H





template <typename T>
class List {
private:
	struct Node {
		// Constructor
		Node(T val);

		// Fields
		T val;
		Node *left_node;
		Node *right_node;
	};

	Node *head; // beginning of list
	Node *tail; // end of list
	Node *after_cursor;
	Node *before_cursor;
	size_t cursor_pos;
	size_t len; // length of list

public:
	/*Constructors*/
	List();

	List(const List &L);

	/*Destructors*/
	~List();

	/*Access Functions*/

	/**
	* @brief returns current length of list
	* @return size_t
	*/
	size_t len() const;

	/**
	* @brief returns front element if present
	* @preq: List must not be empty
	* @return type T
	*/
	T front() const;

	/**
	* @brief returns back element if present
	* @preq: List must not be empty
	* @return type T
	*/
	T back() const;

	/**
	* @brief returns position of cursor 0<=cursor_position<=list.len()
	* @return size_t
	*/
	size_t cursor_position() const;

	/**
	* @brief check right element of cursor
	* @preq: cursor_position() < len()
	* @return type T
	*/
	T peek_right() const;

	/**
	* @brief check left element of cursor
	* @preq: cursor_position() > 0
	* @return type T
	*/
	T peek_left() const;

	/*Manipulation Functions*/

	/**
	* @brief clears list
	*/
	void clear();

	/**
	* @brief sets cursor_pos = 0
	*/
	void cursor_move_head();

	/**
	* @brief sets cursor_pos = len()
	*/
	void cursor_move_tail();

	/**
	* @brief move the cursor 1 position right
	* @preq cursor_pos < len()
	*/
	void move_right();

	/**
	* @brief move the cursor 1 position left
	* @preq cursor_pos > 0
	*/
	void move_left();

	/**
	* @brief Insert new element to right of cursor
	*
	*/
	void insert_right();

	/**
	* @brief Insert new element to left of cursor
	*
	*/
	void insert_left();

	/**
	* @brief Overwrite right element with value
	* @preq len() != 0 && cursor_pos < len()
	*/
	void set_right(T new_element);

	/**
	* @brief Overwrite right element with value
	* @preq len() != 0 && cursor_pos > 0
	*/
	void set_left(T new_element);

	/**
	* @brief erase right element
	* @preq len() != 0 && cursor_pos < len()
	*/
	void erase_right();

	/**
	* @brief erase left element
	* @preq len() != 0 && cursor_pos > 0
	*/
	void erase_left();

}
























#endif
