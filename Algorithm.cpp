#include "Algorothm.h"


float DiscreteWaveformAnalysis::sigmoid(float x) { return 1 / (1 - std::powf(E, x)); }

std::vector<float> maxVector(std::vector<float> vector1, std::vector<float> vector2) {
    return vector1.size() > vector2.size() ? vector1 : vector2;
}


std::vector<float> DiscreteWaveformAnalysis::minVector(std::vector<float> vector1, std::vector<float> vector2) {
    return vector2.size() < vector1.size() ? vector2 : vector1;
}

float DiscreteWaveformAnalysis::dwa(std::vector<float> signal1, std::vector<float> signal2, float lambda) {
    int deltDim = signal1.size() - signal2.size();
    float maximum = 0;
    float result;

    for ( int i = 1; i < abs(deltDim) + 1; i++ ) {
        float sum = 0;
        for ( int j = i; j < std::min((int)signal1.size(), (int)signal2.size()); j++ ) {
            
            float maxReverseDiffSignal = maxVector(signal1, signal2)[j] - maxVector(signal1, signal2)[j - 1];
            float minReverseDiffSignal = minVector(signal1, signal2)[j] - minVector(signal1, signal2)[j - 1];
            float discreteDeltSignalAbs = abs(
                (float)
                (maxReverseDiffSignal - minReverseDiffSignal)
            );

            if ( discreteDeltSignalAbs == 0 ) {
                sum += 1;
            }
            else {
                sum += sigmoid(powf(lambda, -1.f) / discreteDeltSignalAbs);
            }
        }
        result = sum / std::min((int)signal1.size(), (int)signal2.size());
        if ( result > maximum ) {
            maximum = result;
        }
    }
    return maximum;

}

float DiscreteWaveformAnalysis::templateMatching(std::vector<float> signal, std::vector< std::vector<float> > templateMatrix) {
    float num;
    float maximum = 0;
    float result;
    for ( int i = 0; i < templateMatrix.size(); i++ ) {
        result = dwa(signal, templateMatrix[i], 0.1f);
        // std::cout << i << " -- " << result << std::endl;
        if ( result > maximum ) {
            maximum = result;
            num = i;
        }
        
    }

    return num;
}