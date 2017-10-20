/* Logan Seaburg
 *
 * To create these functions I used my lecture notes.
 */

#include "TileStack.h"
#include "strlib.h"

/* Will declare a TileStack that points to a null pointer to indecate that
 * there are no tiles in the stack.
 */
TileStack::TileStack() {
    front = NULL;
}

/* This function calls the clear function when a TileStack goes out of the scope
 * so that the memory is freed.
 */
TileStack::~TileStack() {
    clear();
}

/* Will construct a new tile with the passed parameters and then will place this
 * newly constructed tile in the front of the stack.
 */
void TileStack::pushTile(int x, int y, int width, int height, string color) {
    TileNode* temp = new TileNode (x, y, width, height, color, front);
    front = temp;
}

/* Will loop through the entire stack from top to bottom and calls the displays
 * function for each of the tiles.
 */
void TileStack::drawAll(GWindow& window) const {
    TileNode* curr = front;
    while(curr != NULL) {
        curr->draw(window);
        curr = curr->next;
    }
}

/* Finds the topmost tile that has an occupying piece under the passed coordinate
 * and changes the color of that tile to yellow.
 */
void TileStack::highlight(int x, int y) {
    TileNode*curr = front;
    while (curr != NULL && !curr->contains(x, y)) {
        curr = curr->next;
    }
    if (curr != NULL) {
        curr->color = "yellow";
    }
}

/* Finds the topmost tile that contains a space that occupies the topmost coordinates
 * and will move that tile into the front of the stack.
 */
void TileStack::raise(int x, int y) {
    if (front->contains(x, y)) {
        return;
    }
    TileNode*curr = front;
    while (curr->next != NULL && !curr->next->contains(x, y)) {
        curr = curr->next;
    }
    if (curr->next != NULL) {
        TileNode* temp = curr->next;
        curr->next = curr->next->next;
        temp->next = front;
        front = temp;
    }
}

/* Finds the topmost tile that has a part contained in toe coordinate passed to the function
 * and will remove that tile.
 */
void TileStack::remove(int x, int y) {
    if (front->contains(x, y)) {
        TileNode* temp = front;
        front = front->next;
        delete temp;
    } else {
        TileNode*curr = front;
        while (curr->next != NULL && !curr->next->contains(x, y)) {
            curr = curr->next;
        }
        if (curr->next != NULL) {
            TileNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }
}

/* Will move through the entire TileStack and and delete the tiles one by one to free
 * up the memory that is held in all of the nodes.
 */
void TileStack::clear() {
    while (front != NULL) {
        TileNode* trash = front;
        front = front->next;
        delete trash;
    }
}
