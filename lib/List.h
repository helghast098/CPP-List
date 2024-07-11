////////////////////////////////////////////////
// Created By: Fabert O. Charles
// File: List ADT Function Declarations
///////////////////////////////////////////////
#ifndef LIST_H
#define LIST_H
#include <optional>
#include <cstddef>

/** Class definition **/
template <class T>
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
	size_t length; // length of list

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
	std::optional<T> front() const;

	/**
	* @brief returns back element if present
	* @preq: List must not be empty
	* @return type T
	*/
	std::optional<T> back() const;

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
	std::optional<T> peek_right() const;

	/**
	* @brief check left element of cursor
	* @preq: cursor_position() > 0
	* @return type T
	*/
	std::optional<T> peek_left() const;

	/*Manipulation Functions*/

	/**
	* @brief clears list
	*/
	void clear();

	/**
	* @brief sets cursor_pos = 0
	*/
	void cursor_move_to_head();

	/**
	* @brief sets cursor_pos = len()
	*/
	void cursor_move_to_tail();

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
	void insert_right(T val);

	/**
	* @brief Insert new element to left of cursor
	*
	*/
	void insert_left(T val);

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

/** Template Node Implementation **/
template<class T>
List<T>::Node::Node(T val): val(val), left_node(nullptr), right_node(nullptr) {};

/** Template List Implementation **/

/*Constructor*/
template<class T>
List<T>::List() {
	head = nullptr;
	tail = nullptr;
	after_cursor = nullptr;
	before_cursor = nullptr;
	cursor_pos = 0;
	len = 0;
}

/*length*/
template<class T>
size_t List<t>::len() const {
	return this->length;
}

/*head value*/
template<class T>
std::optional<T> List<T>::front() const {
	if (this->head == nullptr)
	{
		return std::nullopt;
	}

	return this->head->val;
}

/*tail value*/
template<class T>
std::optional<T> List<T>::back() const {
	if (this->tail == nullptr)
	{
		return std::nullopt;
	}

	return this->tail->val;
}

/*cursor position*/
template<class T>
size_t List<T>::cursor_position() const {
	return this->cursor_pos;
}

/*peek_right*/
template<class T>
std::optional<T> List<T>::peek_right() const {
	if (this->cursor_pos == this->length)
	{
		return std::nullopt;
	}
	return this->after_cursor->val;
}

/*peek left*/
template<class T>
std::optional<T> List<T>::peek_left() const {
	if (this->cursor_pos == 0)
	{
		return std::nullopt;
	}
	return this->before_cursor->val;
}

/** Manipulation **/

/*Clear list*/
template<class T>
void List<T>::clear() {
	this->length = 0;
	this->cursor_pos = 0;
	this->after_cursor = nullptr;
	this->before_cursor = nullptr;

	// Deletes all elements 1 by 1
	while (this->head != nullptr)
	{
		Node *holder = this->head->left_node;

		this->head->left_node = nullptr;

		delete this->head;

		if (holder != nullptr)
		{
			holder->right_node = nullptr;
		}
		this->head = holder;
	}

	this->tail = nullptr;
}

/*cursor move to head*/
template<class T>
void List<T>::cursor_move_to_head() {
	this->before_cursor = nullptr;
	this->after_cursor = this->head;
	this->cursor_pos = 0;
}

/*cursor move to tail*/
template<class T>
void List<T>::cursor_move_to_tail() {
	this->after_cursor = nullptr;
	this->before_cursor = this->tail;
	this->cursor_pos = this->length;
}

/*move cursor right*/
template<class T>
void List<T>::move_right() {
	if (this->cursor_pos == this->length)
	{
		return;
	}

	this->before_cursor = this->after_cursor;
	this->after_cursor = this->after_cursor->right_node;
	this->cursor_pos += 1;
}

/*move cursor left*/
template<class T>
void List<T>::move_left() {
	if (this->cursor_pos == 0)
	{
		return;
	}

	this->after_cursor = this->before_cursor;
	this->before_cursor = this->before_cursor->left_node;
	this->cursor_pos -= 1;
}

/*insert to right of cursor*/
template<class T>
void List<T>::insert_right(T val) {
	// Creating the node
	Node *new_node = new Node(val);

	if (this->cursor_pos == 0)
	{
		if (this->head != nullptr)
		{
			this->head->left_node = new_node;
			new_node->right_node = this->head;
		}
		else
		{
			this->tail = new_node;
		}
		this->head = new_node;
	}
	else if (this->cursor_pos == this->length)
	{
		this->tail->right_node = new_node;
		new_node->left_node = this->tail;
		this->tail = new_node;
	}
	else
	{
		// Fix left node
		this->before_cursor->right_node = new_node;
		new_node->left_node = this->before_cursor;

		// Fix right node
		this->after_cursor->left_node = new_node;
		new_node->right_node = this->after_cursor;
	}

	this->after_cursor = new_node;

	this->length += 1;
}























#endif
