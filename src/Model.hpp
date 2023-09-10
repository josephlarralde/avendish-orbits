#pragma once
#include <avnd/concepts/callback.hpp>
#include <halp/callback.hpp>
#include <halp/controls.hpp>
#include <halp/meta.hpp>
#include "../orbits/src/Orbits.h"

class AvndOrbits
{
public:
  halp_meta(name, "AvndOrbits")
  halp_meta(c_name, "orbits")
  halp_meta(uuid, "6ab6cfa4-7303-41fb-847d-58c99c3f2a19")

  std::unique_ptr<Orbits::Orbits<3>> orbits;

  struct ins {
    // struct {
    //   static consteval auto name() { return "size"; }
    //   std::size_t value;
    // } size;
    // halp::hslider_f32<"Gain", halp::range{.min = 0., .max = 10., .init = 0.5}> gain;
  } inputs;

  struct {
    struct {
      static consteval auto name() { return "out"; }
      halp::basic_callback<void(std::vector<float>&)> call;
      // halp::basic_callback<void(std::ranges::input_range)> call;
      // help::basic_callback<void(float)> call;
    } out;
  } outputs;

  struct {
    struct {
      static consteval auto name() { return "size"; }
      static consteval auto func() { return &AvndOrbits::size; }
    } size_msg;

    struct {
      static consteval auto name() { return "bang"; }
      static consteval auto func() { return &AvndOrbits::bang; }
    } bang_msg;
  } messages;

  void size(int s) {
    orbits->setSize(s < 0 ? 0 : s);
    std::vector<float> v = { 3, 2, 1, 0 };
    outputs.out.call(v);
    // outputs.out.call({ 0, 1, 2, 3 });
  }

  void bang() {
    orbits->step();
    std::vector<float> v = { 0, 1, 2, 3 };
    outputs.out.call(v);
    // outputs.out.call({ 3, 2, 1, 0 });
  }

  // this is where we'd manage init arguments
  void initialize() {
    orbits.reset(new Orbits::Orbits<3>());
  }

  // void operator()(double** ins, double** outs, int N);
  void operator()();

  // Defined in UI.hpp
  struct ui;

private:

};