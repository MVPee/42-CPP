# include "MutantStack.hpp"
# include <list>

int main() {
    std::cout << "*** PART1: Basic MutantStack operations ***" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl; 
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterating over stack elements:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "*** PART2: Copying and assigning MutantStack ***" << std::endl;
    MutantStack<int> mstack_copy(mstack);
    std::cout << "Copy constructor, stack contents:" << std::endl;
    for (MutantStack<int>::iterator it = mstack_copy.begin(); it != mstack_copy.end(); ++it) {
        std::cout << *it << std::endl;  // Should print same elements as mstack
    }

    MutantStack<int> mstack_assigned;
    mstack_assigned.push(42); 
    std::cout << "Before assignment, stack contents:" << std::endl;
    for (MutantStack<int>::iterator it = mstack_assigned.begin(); it != mstack_assigned.end(); ++it) {
        std::cout << *it << std::endl;  // Should print 42
    }
    mstack_assigned = mstack;
    std::cout << "After assignment, stack contents:" << std::endl;
    for (MutantStack<int>::iterator it = mstack_assigned.begin(); it != mstack_assigned.end(); ++it) {
        std::cout << *it << std::endl;  // Should print same elements as mstack
    }

    std::cout << "*** PART3: Using MutantStack with std::stack and std::list ***" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "std::stack constructed from MutantStack, top element: " << s.top() << std::endl;

    std::list<int> l(mstack.begin(), mstack.end());
    std::cout << "std::list constructed from MutantStack, list contents:" << std::endl;
    for (std::list<int>::iterator lit = l.begin(); lit != l.end(); ++lit) {
        std::cout << *lit << std::endl;  // Should print same elements as mstack
    }

    std::cout << "*** PART4: Edge cases and additional tests ***" << std::endl;
    MutantStack<int> empty_stack;
    std::cout << "Empty stack, size: " << empty_stack.size() << std::endl;
    if (empty_stack.empty()) {
        std::cout << "Stack is empty!" << std::endl;
    }

    while (!mstack.empty()) {
        std::cout << "Popping top element: " << mstack.top() << std::endl;
        mstack.pop();
    }
    std::cout << "Size after popping all elements: " << mstack.size() << std::endl;

    return 0;
}
