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

	/*Helper Functions*/
	void insert_node_at_cursor(Node *new_node);

public:
	/*Constructors*/
	List();

	List(const List &L);

	/*Destructors*/
	~List();

	/*Access Functions*/

	/**
	* @brief returns 	// Creating the node
current length of list
	* @return size_t
	*/
	size_t len() const;

	/**
	* @brief returns front element if present
	* @preq: List must not be empty
	* @return type optional<T>
	*/
	std::optional<T> front() const;

	/**
	* @brief returns back element if present
	* @preq: List must not be empty
	* @return type optional<T>
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
	* @return type optional<T>
	*/
	std::optional<T> peek_right() const;

	/**
	* @brief check left element of cursor
	* @preq: cursor_position() > 0
	* @return type optional<T>
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
	* @note won't do anything if preq not met
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
	* @note won't do anything if preq not met
	*/
	void set_right(T new_element);

	/**
	* @brief Overwrite right element with value
	* @preq len() != 0 && cursor_pos > 0
	* @note won't do anything if preq not met
	*/
	void set_left(T new_element);

	/**
	* @brief erase right element
	* @preq len() != 0 && cursor_pos < len()
	* @note won't do anything if preq not met
	*/
	void erase_right();

	/**
	* @brief erase left element
	* @preq len() != 0 && cursor_pos > 0
	* @note won't do anything if preq not met
	*/
	void erase_left();
};

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
	length = 0;
}

/*Destructor*/
template<class T>
List<T>::~List() {
	this->clear();
}

/*length*/
template<class T>
size_t List<T>::len() const {
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
	while (this->tail != nullptr)
	{
		Node *holder = this->tail->left_node;

		this->tail->left_node = nullptr;

		delete this->tail;

		if (holder != nullptr)
		{
			holder->right_node = nullptr;
		}
		this->tail = holder;
	}

	this->head = nullptr;
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
	// Inserting Node
	Node *new_node = new Node(val);
	this->insert_node_at_cursor(new_node);

	this->after_cursor = new_node;
	this->length += 1;
}

/*insert left of cursor*/
template<class T>
void List<T>::insert_left(T val) {
	// Creating the node
	Node *new_node = new Node(val);
	this->insert_node_at_cursor(new_node);

	this->before_cursor = new_node;
	this->cursor_pos += 1;
	this->length += 1;
}

/*set right node value*/
template<class T>
void List<T>::set_right(T new_element) {
	if (this->after_cursor != nullptr)
	{
		this->after_cursor->val = new_element;
	}
}

/*set right node value*/
template<class T>
void List<T>::set_left(T new_element) {
	if (this->before_cursor != nullptr)
	{
		this->before_cursor->val = new_element;
	}
}

template<class T>
void List<T>::erase_right() {
	if (this->after_cursor == nullptr)
	{
		return;
	}

	Node *holder = nullptr;

	if (this->after_cursor == this->head)
	{
		holder = this->after_cursor;

		this->head = holder->right_node;

		if (holder == this->tail)
		{
			this->tail = nullptr;
		}
	}
	else
	{
		holder = this->after_cursor;
		holder->left_node->right_node = holder->right_node;

		if (holder == this->tail)
		{
			this->tail = holder->left_node;
		}
	}

	if (holder->right_node != nullptr)
	{
		holder->right_node->left_node = holder->left_node;
	}
	this->length -= 1;
	this->after_cursor = holder->right_node;

	holder->left_node = nullptr;
	holder->right_node = nullptr;
	delete holder;
}

template<class T>
void List<T>::erase_left() {
	if (this->before_cursor == nullptr)
	{
		return;
	}

	Node *holder = nullptr;

	if (this->before_cursor == this->tail)
	{
		holder = this->tail;

		if (holder == this->head)
		{
			this->head = nullptr;
		}
		this->tail = holder->left_node;
	}
	else
	{
		holder = this->before_cursor;

		holder->right_node->left_node = holder->left_node;

		if (holder == this->head)
		{
			this->head = holder->right_node;
		}
	}

	if (holder->left_node != nullptr)
	{
		holder->left_node->right_node = holder->right_node;
	}
	this->length -= 1;
	this->cursor_pos -= 1;
	this->before_cursor = holder->left_node;

	holder->left_node = nullptr;
	holder->right_node = nullptr;
	delete holder;

}

/**Helper Functions**/
template<class T>
void List<T>::insert_node_at_cursor(Node *new_node) {

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
}





















#endif
