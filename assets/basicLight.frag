#version 330 core
// basicLight.frag
in vec4 vColor;
in vec3 vNormal;
in vec3 FragPos;

out vec4 FragColor;

uniform vec3 lightPos;
uniform vec3 lightColor; // keep as vec3 (matches glUniform3f in C++)

void main()
{
    // normalize vectors
    vec3 norm = normalize(vNormal);
    vec3 lightDir = normalize(lightPos - FragPos);

    // diffuse lighting
    float diff = max(dot(norm, lightDir), 0.0);

    // small ambient so object is still visible when not directly lit
    vec3 ambient = 0.2 * vColor.rgb;

    vec3 result = ambient + diff * lightColor * vColor.rgb;

    FragColor = vec4(result, vColor.a);
}