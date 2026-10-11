
#include <iostream>

using namespace std;

class Perceptron {
private:
    double w1, w2;
    double bias;
    double learning_r;

public:
    Perceptron(double lr) {
        w1 = 0;
        w2 = 0;
        bias = 0;
        learning_r = lr;
    }

    int step(double output) {
        return output >= 0 ? 1 : 0;
    }

    int predict(double x1, double x2) {
        double z = x1 * w1 + x2 * w2 + bias;
        return step(z);
    }

    void train(double x1, double x2, int target) {
        int output = predict(x1, x2);
        int error = target - output;

        w1 += learning_r * error * x1;
        w2 += learning_r * error * x2;
        bias += learning_r * error;
    }

    void show_weights() {
        cout << "w1 = " << w1 << endl;
        cout << "w2 = " << w2 << endl;
        cout << "bias = " << bias << endl;
    }
};

int main() {
    Perceptron p(0.1);

    // Input: OR gate
    double inputs[4][2] = {
        {0, 1},
        {1, 1},
        {1, 0},
        {0, 0}
    };

    int targets[4] = {1, 1, 1, 0};

    // Train
    for (int epoch = 0; epoch < 11; epoch++) {
        for (int i = 0; i < 4; i++) {
            p.train(
                inputs[i][0],
                inputs[i][1],
                targets[i]
            );
        }
    }

    // Output
    cout << "Learned weights:" << endl;
    p.show_weights();

    cout << "Predictions:" << endl;

    for (int i = 0; i < 4; i++) {
        int output = p.predict(inputs[i][0], inputs[i][1]);

        cout << inputs[i][0] << " OR "
             << inputs[i][1] << " = "
             << output << endl;
    }

    return 0;
}

