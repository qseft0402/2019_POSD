#ifndef FLATTENEND_VISITOR_H
#define FLATTENEND_VISITOR_H

#include "set_visitor.h"
#include "set.h"
#include <vector>
#include <iostream>

class FlattenedVisitor : public SetVisitor {
    public:
        FlattenedVisitor() : _flattenedSet(nullptr) {
        }

        void visitSet(Set* set) {
            std::vector<int> numbers;
            this->searchValue(*set, numbers);

            this->_flattenedSet = new Set();
            for (int num : numbers) {
                this->_flattenedSet->add(num);
            }
        }

        Set* getResult() {
            return this->_flattenedSet;
        }

    private:
        void searchValue(Set target, std::vector<int>& result) {
            Set::SetIterator* it = target.createItr();

            for (it->first(); !it->isDone(); it->next()) {
                if (it->currentItem().isPureNum()) {
                    result.push_back(it->currentItem().getPureNum());
                }

                this->searchValue(it->currentItem(), result);
            }
        }

        Set* _flattenedSet;
};

#endif