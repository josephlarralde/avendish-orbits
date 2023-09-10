#include "Processor.hpp"

// void AvndOrbits::operator()(double** ins, double** outs, int N)
// {
//   for (int i = 0; i < channels(); i++)
//   {
//     auto* in = ins[i];
//     auto* out = outs[i];
//     for (int j = 0; j < N; j++)
//     {
//       out[j] = in[j] * inputs.gain;
//     }
//   }
// }

void AvndOrbits::operator()()
{
  std::vector<float> v = { 0, 1, 2, 3 };
  outputs.out.call(v);
  // outputs.out.call(0);
  // outputs.out.call({ 0, 1, 2, 3 });
}