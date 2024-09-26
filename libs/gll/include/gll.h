/*
** EPITECH PROJECT, 2023
** GLL
** File description:
** GLL
*/

#ifndef GLL
    #define GLL

    #include <stdbool.h>

/**
 * @brief Represents a node in the generic linked list.
 */
typedef struct node_s {
    void *data; /**< The data stored in the node. */
    struct node_s *prev; /**< A pointer to the previous node. */
    struct node_s *next; /**< A pointer to the next node. */
} gll_node_t;

/**
 * @brief Represents a generic linked list.
 */
typedef struct gll_s {
    int size; /**< The size of the linked list. */
    gll_node_t *first; /**< A pointer to the first node in the linked list. */
    gll_node_t *last; /**< A pointer to the last node in the linked list. */
} gll_t;

gll_node_t *gll_find_node(gll_t *list, int pos);
gll_node_t *gll_init_node(void *);

/**
 * @brief Initializes a new instance of the generic linked list.
 *
 * @return A pointer to the newly initialized linked list.
 */
gll_t *gll_init(void);

/**
 * @brief Retrieves the element at the specified index in the linked list.
 *
 * @param list The linked list.
 * @param index The index of the element to retrieve.
 * @return A pointer to the element at the specified index,
 * or NULL if the index is out of range.
 */
void *gll_get(gll_t *list, int index);

/**
 * @brief Retrieves the first element in the linked list.
 *
 * @param list The linked list.
 * @return A pointer to the first element, or NULL if the list is empty.
 */
void *gll_first(gll_t *list);

/**
 * @brief Retrieves the last element in the linked list.
 *
 * @param list The linked list.
 * @return A pointer to the last element, or NULL if the list is empty.
 */
void *gll_last(gll_t *list);

/**
 * @brief Checks if the linked list is empty.
 *
 * @param list The linked list.
 * @return true if the list is empty, false otherwise.
 */
bool gll_empty(gll_t *list);

/**
 * @brief Adds an element to the linked list at the specified index.
 *
 * @param list The linked list.
 * @param element The element to add.
 * @param index The index at which to add the element.
 * @return 0 if the element was added successfully, -1
 * if the index is out of range.
 */
int gll_add(gll_t *list, void *element, int index);

/**
 * @brief Sets the element at the specified index in the linked list.
 *
 * @param list The linked list.
 * @param element The new element to set.
 * @param index The index of the element to set.
 * @return A pointer to the previous element at the
 * specified index, or NULL if the index is out of range.
 */
void *gll_set(gll_t *list, void *element, int index);

/**
 * @brief Pushes an element to the front of the linked list.
 *
 * @param list The linked list.
 * @param element The element to push.
 * @return 0 if the element was pushed successfully, -1 if an error occurred.
 */
int gll_push(gll_t *list, void *element);

/**
 * @brief Pushes an element to the back of the linked list.
 *
 * @param list The linked list.
 * @param element The element to push.
 * @return 0 if the element was pushed successfully, -1 if an error occurred.
 */
int gll_push_back(gll_t *list, void *element);

/**
 * @brief Removes the element at the specified index from the linked list.
 *
 * @param list The linked list.
 * @param index The index of the element to remove.
 * @return A pointer to the removed element,
 * or NULL if the index is out of range.
 */
void *gll_remove(gll_t *list, int index);

/**
 * @brief Pops the first element from the linked list.
 *
 * @param list The linked list.
 * @return A pointer to the popped element, or NULL if the list is empty.
 */
void *gll_pop(gll_t *list);

/**
 * @brief Pops the last element from the linked list.
 *
 * @param list The linked list.
 * @return A pointer to the popped element, or NULL if the list is empty.
 */
void *gll_pop_back(gll_t *list);

/**
 * @brief Applies a function to each element in the linked list.
 *
 * @param list The linked list.
 * @param f The function to apply to each element.
 */
void gll_each(gll_t *list, void (*f)(void *));

/**
 * @brief Applies a function to each element
 * in the linked list in reverse order.
 *
 * @param list The linked list.
 * @param f The function to apply to each element.
 */
void gll_each_reverse(gll_t *list, void (*f)(void *));

/**
 * @brief Clears the linked list, removing all elements.
 *
 * @param list The linked list.
 */
void gll_clear(gll_t *list);

/**
 * @brief Destroys the linked list, freeing all allocated memory.
 *
 * @param list The linked list.
 */
void gll_destroy(gll_t *list);

#endif /* !GLL */
