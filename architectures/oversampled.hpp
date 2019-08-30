//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: {{file_name}}
// Name: {{name}}
// Author: {{author}}
// Copyright: {{copyright}}
// License: {{license}}
// Version: {{version}}
//------------------------------------------------------------------------------

#pragma once
#ifndef {{Identifier}}_Faust_pp_Gen_HPP_
#define {{Identifier}}_Faust_pp_Gen_HPP_

#include <memory>

class {{class_name}};

class {{Identifier}} {
public:
    {{Identifier}}();
    ~{{Identifier}}();

    void init(float sample_rate);
    void clear() noexcept;

    void process(
        {% for i in range(inputs) %}const float *in{{i}},{% endfor %}
        {% for i in range(outputs) %}float *out{{i}},{% endfor %}
        unsigned count) noexcept;

    enum { NumInputs = {{inputs}} };
    enum { NumOutputs = {{outputs}} };
    enum { NumParameters = {{length(active)}} };

    enum Parameter {
        {% for w in active %}p_{{cid(default(w.meta.symbol,w.label))}},
        {% endfor %}
    };

    struct ParameterRange {
        float init;
        float min;
        float max;
    };

    static const char *parameter_label(unsigned index) noexcept;
    static const char *parameter_short_label(unsigned index) noexcept;
    static const char *parameter_symbol(unsigned index) noexcept;
    static const char *parameter_unit(unsigned index) noexcept;
    static const ParameterRange *parameter_range(unsigned index) noexcept;
    static bool parameter_is_trigger(unsigned index) noexcept;
    static bool parameter_is_boolean(unsigned index) noexcept;
    static bool parameter_is_integer(unsigned index) noexcept;
    static bool parameter_is_logarithmic(unsigned index) noexcept;

    float get_parameter(unsigned index) const noexcept;
    void set_parameter(unsigned index, float value) noexcept;

    {% for w in active %}
    float get_{{cid(default(w.meta.symbol,w.label))}}() const noexcept;
    void set_{{cid(default(w.meta.symbol,w.label))}}(float value) noexcept;
    {% endfor %}

    {% if Oversampling >= 2 %}
private:
    void process_segment(const float *const inputs[], float *const outputs[], unsigned count) noexcept;
    {% endif %}

private:
    std::unique_ptr<{{class_name}}> fDsp;

    {% if Oversampling >= 2 %}
    struct Oversampler;
    std::unique_ptr<Oversampler> fOversampler;
    {% endif %}
};

#endif // {{Identifier}}_Faust_pp_Gen_HPP_