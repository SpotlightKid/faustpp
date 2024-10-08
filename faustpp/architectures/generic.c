{% block ImplementationDescription %}
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/SpotlightKid/faustpp).
//
// Source: {{file_name}}
// Name: {{name}}
// Author: {{author}}
// Copyright: {{copyright}}
// License: {{license}}
// Version: {{version}}
// FAUST version: {{faust_version}}
// FAUST compilation options: {{meta.compile_options}}
//------------------------------------------------------------------------------
{% endblock %}
{% block ImplementationPrologue %}
{% endblock %}
{% block ImplementationIncludeHeader %}
#include "{{class_name}}.h"
{% endblock %}
{% block ImplementationIncludeExtra %}
{% endblock %}

//------------------------------------------------------------------------------
// Begin the Faust code section

{% block ImplementationFaustCode %}
#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

{{class_code}}

#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif
{% endblock %}

//------------------------------------------------------------------------------
// End the Faust code section

{% block ImplementationEpilogue %}
{% endblock %}
