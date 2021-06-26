#include <iostream>

using namespace std;

class LaneOutOfBounds {};
class NotADirection {};
class PossibleCollisionDetected {};

int main() {
    const int MIN_LANE = 1;
    const int MAX_LANE = 10;
    const int UP = 1;
    const int DOWN = -1;
    const int STOPPED = 0;

    int arr[10] = {0};

    cout << "Lane  :Enter lanes between " << MIN_LANE << " and " << MAX_LANE
         << endl;
    cout << "State :Enter " << UP << " for up direction, " << DOWN
         << " for down direction" << endl
         << "       or " << STOPPED << " if the vehicle is stopped" << endl;
    cout << "Keep entering a vehicle into the system!" << endl;

    int lane;
    int direction;
    bool loop = true;
    try {
        while (loop) {
            cout << "Enter lane : ";
            cin >> lane;
            if (lane < MIN_LANE || lane > MAX_LANE) throw LaneOutOfBounds();
            cout << "Enter direction : ";
            cin >> direction;
            if (direction < DOWN || direction > UP) throw NotADirection();
            if (arr[lane - 1] * direction < 0)
                throw PossibleCollisionDetected();
            arr[lane -1] = direction;
            cout << "Normal state! Keep Going!" << endl;
        }
    } catch (LaneOutOfBounds l) {
        cout << "Lane does nor exist!" << endl;
    } catch (NotADirection n) {
        cout << "Not a valid direction!" << endl;
    } catch (PossibleCollisionDetected p) {
        cout << "Possible Collision detected!" << endl;
    }
}
