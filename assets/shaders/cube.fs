#version 330 core
out vec4 FragColor;

in vec3 Normal;  
in vec3 FragPos;  
in vec2 TexCoords;


uniform vec3 viewPos; //camera
uniform vec3 lightPos;  //position of the light
uniform vec3 lightColor;    //value of the color of the light

uniform sampler2D textureAtlas; //sample texture rgb for result lighting calculation

void main()
{
    // // ambient
    // float ambientStrength = 0.8;
    // vec3 ambient = ambientStrength * lightColor;
  	
    // // diffuse 
    // vec3 norm = normalize(Normal);  //find normal vector
    // vec3 lightDir = normalize(lightPos - FragPos);  //
    // float diff = max(dot(norm, lightDir), 0.0);
    // vec3 diffuse = diff * lightColor;
            
    // // specular
    // float specularStrength = 0.5;
    // vec3 viewDir = normalize(viewPos - FragPos);
    // vec3 reflectDir = reflect(-lightDir, norm);  
    // float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    // vec3 specular = specularStrength * spec * lightColor;  
        
    // // combine lighting to texture
    vec3 textureColor = texture(textureAtlas, TexCoords).rgb; //sample texture color
    // vec3 result = (ambient + diffuse + specular) * textureColor;
    vec3 result = textureColor;

    FragColor = vec4(result, 1.0);
} 

