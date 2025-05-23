#ifndef DISCRETE_WAVEFORM_ANALYSIS
#define DISCRETE_WAVEFORM_ANALYSIS

#define E 2.7182f

#include <iostream>
#include <vector>
#include <cmath>


class DiscreteWaveformAnalysis {
public:
    float sigmoid(float x);

    std::vector<float> maxVector(std::vector<float> vector1, std::vector<float> vector2);
    std::vector<float> minVector(std::vector<float> vector1, std::vector<float> vector2);

    float dwa(std::vector<float> signal1, std::vector<float> signal2, float lambda);
    
    float templateMatching(std::vector<float> signal, std::vector< std::vector<float> > templateMatrix);
};


#endif