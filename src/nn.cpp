#include <algorithm>
#include <cstdint>
#include <vector>

#include <iostream>
#include <omp.h>

#include <nn.hpp>
#include <rng.hpp>

using namespace std;

uniform_real_distribution<float> uniform(-1.f, 1.f);

namespace PijersiEngine
{
    void cellsToInput(uint8_t cells[45], uint8_t currentPlayer, uint8_t input[720])
    {
        if (currentPlayer == 0)
        {
            for (int k = 0; k < 45; k++)
            {
                if (cells[k] != 0)
                {
                    switch (cells[k] & 14)
                    {
                    case 0:
                        input[k * 16] = 1;
                        break;
                    case 4:
                        input[k * 16 + 1] = 1;
                        break;
                    case 8:
                        input[k * 16 + 2] = 1;
                        break;
                    case 12:
                        input[k * 16 + 3] = 1;
                        break;
                    case 2:
                        input[k * 16 + 4] = 1;
                        break;
                    case 6:
                        input[k * 16 + 5] = 1;
                        break;
                    case 10:
                        input[k * 16 + 6] = 1;
                        break;
                    case 14:
                        input[k * 16 + 7] = 1;
                        break;
                    }
                    if (cells[k] >= 16)
                    {
                        switch (cells[k] & 224)
                        {
                        case 0:
                            input[k * 16 + 8] = 1;
                            break;
                        case 64:
                            input[k * 16 + 9] = 1;
                            break;
                        case 128:
                            input[k * 16 + 10] = 1;
                            break;
                        case 192:
                            input[k * 16 + 11] = 1;
                            break;
                        case 32:
                            input[k * 16 + 12] = 1;
                            break;
                        case 96:
                            input[k * 16 + 13] = 1;
                            break;
                        case 160:
                            input[k * 16 + 14] = 1;
                            break;
                        case 224:
                            input[k * 16 + 15] = 1;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            for (int k = 0; k < 45; k++)
            {
                if (cells[44 - k] != 0)
                {
                    switch (cells[44 - k] & 14)
                    {
                    case 2:
                        input[k * 16] = 1;
                        break;
                    case 6:
                        input[k * 16 + 1] = 1;
                        break;
                    case 10:
                        input[k * 16 + 2] = 1;
                        break;
                    case 14:
                        input[k * 16 + 3] = 1;
                        break;
                    case 0:
                        input[k * 16 + 4] = 1;
                        break;
                    case 4:
                        input[k * 16 + 5] = 1;
                        break;
                    case 8:
                        input[k * 16 + 6] = 1;
                        break;
                    case 12:
                        input[k * 16 + 7] = 1;
                        break;
                    }
                    if (cells[44 - k] >= 16)
                    {
                        switch (cells[k] & 224)
                        {
                        case 32:
                            input[k * 16 + 8] = 1;
                            break;
                        case 96:
                            input[k * 16 + 9] = 1;
                            break;
                        case 160:
                            input[k * 16 + 10] = 1;
                            break;
                        case 224:
                            input[k * 16 + 11] = 1;
                            break;
                        case 0:
                            input[k * 16 + 12] = 1;
                            break;
                        case 64:
                            input[k * 16 + 13] = 1;
                            break;
                        case 128:
                            input[k * 16 + 14] = 1;
                            break;
                        case 192:
                            input[k * 16 + 15] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    float _sigmoid(float input)
    {
        return 1.f/(1.f + exp(-input));
    }

    float _dSigmoid(float input)
    {
        return input * (1 - input);
    }

    float _leakyRelu(float input)
    {
        // return max(0.f, input);
        return max(0.01f * input, input);
    }

    float _dLeakyRelu(float input)
    {
        return (input > 0) ? 1 : 0.01f;
        // return (input > 0) ? 1 : 0.f;
    }

    void Layer::load()
    {
    }

    template <typename T>
    void Layer::forward(T *input, float *output)
    {
        for (int i = 0; i < outputSize; i++)
        {
            float sum = 0;
            for (int j = 0; j < inputSize; j++)
            {
                sum += weights[i * inputSize + j] * input[j];
            }
            if (activation)
            {
                output[i] = _sigmoid(sum + biases[i]);
            }
            else
            {
                output[i] = _sigmoid(sum + biases[i]) - 0.5f;
            }
        }
    }

    void Layer::update(float learningRate, float *weightError, float *biasError)
    {
        for (int i = 0; i < inputSize * outputSize; i++)
        {
            weights[i] -= learningRate * weightError[i];
        }
        for (int i = 0; i < outputSize; i++)
        {
            biases[i] -= learningRate * biasError[i];
        }
    }

    Layer::Layer(int newInputSize, int newOutputSize, bool newUseActivation)
    {
        inputSize = newInputSize;
        outputSize = newOutputSize;
        activation = newUseActivation;

        if (inputSize != 0 && outputSize != 0)
        {
            weights = new float[inputSize * outputSize];
            biases = new float[outputSize];
        }

        for (int i = 0; i < inputSize * outputSize; i++)
        {
            weights[i] = uniform(gen);
        }
        for (int i = 0; i < outputSize; i++)
        {
            biases[i] = uniform(gen);
        }
    }

    Layer::~Layer()
    {
        delete weights;
        delete biases;
    }

    Dense720x256::Dense720x256() : Layer(720, 256, true)
    {
    }

    Dense256x32::Dense256x32() : Layer(256, 32, true)
    {
    }

    Dense32x32::Dense32x32() : Layer(32, 32, true)
    {
    }

    Dense32x1::Dense32x1() : Layer(32, 1, false)
    {
    }

    void Network::setInput(uint8_t cells[45], uint8_t currentPlayer)
    {
        // TODO: change this when implementing incremental updates
        for (int i = 0; i < 720; i++)
        {
            input[i] = 0;
        }
        cellsToInput(cells, currentPlayer, input);
    }

    float Network::forward()
    {

        // -> uint8_t[720];
        layer1.forward(input, output1);
        // -> float[256];
        layer2.forward(output1, output2);
        // -> float[32];
        layer3.forward(output2, output3);
        // -> float[32];
        layer4.forward(output3, output4);
        // -> float[1];
        return *output4;
    }

    Trainer::Trainer(int newBatchSize)
    {
        batchSize = newBatchSize;

        inputs = new uint8_t[720 * batchSize];
        outputs1 = new float[256 * batchSize];
        outputs2 = new float[32 * batchSize];
        outputs3 = new float[32 * batchSize];
        outputs4 = new float[batchSize];

        targets = new float[batchSize];

        errors1 = new float[256 * batchSize];
        errors2 = new float[32 * batchSize];
        errors3 = new float[32 * batchSize];
        errors4 = new float[batchSize];
    }

    void Trainer::setInput(uint8_t cells[45], uint8_t currentPlayer, float target, int batchIndex)
    {
        for (int i = 0; i < 720; i++)
        {
            inputs[batchIndex * 720 + i] = 0;
        }
        cellsToInput(cells, currentPlayer, inputs + batchIndex * 720);
        targets[batchIndex] = target;
    }

    void Trainer::forward()
    {
#pragma omp parallel for
        for (int batchIndex = 0; batchIndex < batchSize; batchIndex++)
        {
            // Inference
            // TODO: make thread safe
            network.layer1.forward(inputs + 720 * batchIndex, outputs1 + 256 * batchIndex);
            network.layer2.forward(outputs1 + 256 * batchIndex, outputs2 + 32 * batchIndex);
            network.layer3.forward(outputs2 + 32 * batchIndex, outputs3 + 32 * batchIndex);
            network.layer4.forward(outputs3 + 32 * batchIndex, outputs4 + batchIndex);
        }
    }

    float Trainer::loss()
    {
        float sum = 0.f;
        for (int batchIndex = 0; batchIndex < batchSize; batchIndex++)
        {
            sum += (targets[batchIndex] - outputs4[batchIndex]) * (targets[batchIndex] - outputs4[batchIndex]);
        }
        return 10.f * sum / batchSize;
    }

    void Trainer::back(float learningRate)
    {
        // TODO: Streamline and put redundant code into separate functions
#pragma omp parallel for
        for (int batchIndex = 0; batchIndex < batchSize; batchIndex++)
        {
            errors4[batchIndex] = outputs4[batchIndex] - targets[batchIndex] * _dSigmoid(outputs4[batchIndex]);
            // errors4[batchIndex] = outputs4[batchIndex] - targets[batchIndex];

            for (int i = 0; i < 32; i++)
            {
                errors3[32 * batchIndex + i] = network.layer4.weights[i] * errors4[batchIndex] * _dSigmoid(outputs3[32 * batchIndex + i]);
            }

            for (int i = 0; i < 32; i++)
            {
                float sum = 0.f;
                for (int j = 0; j < 32; j++)
                {
                    sum += network.layer3.weights[j * 32 + i] * errors3[batchIndex * 32 + j] * _dSigmoid(outputs2[32 * batchIndex + i]);
                }
                errors2[batchIndex * 32 + i] = sum;
            }

            for (int i = 0; i < 256; i++)
            {
                float sum = 0.f;
                for (int j = 0; j < 32; j++)
                {
                    sum += network.layer2.weights[j * 256 + i] * errors2[batchIndex * 32 + j] * _dSigmoid(outputs1[256 * batchIndex + i]);
                }
                errors1[batchIndex * 256 + i] = sum;
            }
        }

        // for (int i = 0; i < batchSize; i++)
        // {
            cout << "Target: " << targets[0] << " Prediction: " << outputs4[0] << " Error: " << errors4[0] << endl;
        // }

        float biasError1[256] = {0.f};
        float biasError2[32] = {0.f};
        float biasError3[32] = {0.f};
        float biasError4[1] = {0.f};

        // TODO: cache optimisation
        for (int batchIndex = 0; batchIndex < batchSize; batchIndex++)
        {
            *biasError4 += errors4[batchIndex];
        }
        for (int batchIndex = 0; batchIndex < batchSize; batchIndex++)
        {
            for (int i = 0; i < 32; i++)
            {
                biasError3[i] += errors3[batchIndex * 32 + i];
                biasError2[i] += errors2[batchIndex * 32 + i];
            }
            for (int i = 0; i < 256; i++)
            {
                biasError1[i] += errors1[batchIndex * 256 + i];
            }
        }

        float weightError1[720 * 256] = {0};
        float weightError2[256 * 32] = {0};
        float weightError3[32 * 32] = {0};
        float weightError4[32] = {0};

        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 720; j++)
            {
                float sum = 0.f;
                for (int batchIndex = 0; batchIndex < batchSize; batchIndex++)
                {
                    sum += errors1[batchIndex * 256 + i] * inputs[batchIndex * 720 + j];
                }
                weightError1[i * 720 + j] = sum * 2.f / (float)batchSize;
            }
        }

        for (int i = 0; i < 32; i++)
        {
            for (int j = 0; j < 256; j++)
            {
                float sum = 0.f;
                for (int batchIndex = 0; batchIndex < batchSize; batchIndex++)
                {
                    sum += errors2[batchIndex * 32 + i] * outputs1[batchIndex * 256 + j];
                }
                weightError2[i * 256 + j] = sum * 2.f / (float)batchSize;
            }
        }

        for (int i = 0; i < 32; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                float sum = 0.f;
                for (int batchIndex = 0; batchIndex < batchSize; batchIndex++)
                {
                    sum += errors3[batchIndex * 32 + i] * outputs2[batchIndex * 32 + j];
                }
                weightError3[i * 32 + j] = sum * 2.f / (float)batchSize;
            }
        }

        for (int i = 0; i < 32; i++)
        {
            float sum = 0.f;
            for (int batchIndex = 0; batchIndex < batchSize; batchIndex++)
            {
                sum += errors4[batchIndex] * outputs3[batchIndex * 32 + i];
            }
            // weightError4[i] = sum * 2.f / (float)batchSize;
            // cout << sum << " ";
        }
        // cout << endl;

        network.layer1.update(learningRate, weightError1, biasError1);
        network.layer2.update(learningRate, weightError2, biasError2);
        network.layer3.update(learningRate, weightError3, biasError3);
        network.layer4.update(learningRate, weightError4, biasError4);
    }

    Trainer::~Trainer()
    {
        delete inputs;
        delete outputs1;
        delete outputs2;
        delete outputs3;
        delete outputs4;
        delete targets;
        delete errors1;
        delete errors2;
        delete errors3;
        delete errors4;
    }
}