#include "LinkedList.h"

#include <string>

// Returns the number of elements
size_t List::size() const {
    return m_size;
}


// Returns a std::string equivalent of the container
std::string List::to_string() const {

    std::string output = "[";
    for(Node* curr = m_head;curr;curr = curr->next)
    {
        output = output + std::to_string(curr->element);
        if (curr->next)
            output += ",";
    }
    output += "]";
    return output;
}
