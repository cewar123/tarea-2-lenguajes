#include <vector>
#include <iostream>
#include <string>

// Definimos los tipos de instrucciones manualmente (Estilo C++11)
enum InstructionType { INJECT, CHECK_TEMP, LOOP };

struct OpCode {
    InstructionType type;
    double value;
    // Constructor simple para facilitar uso
    OpCode(InstructionType t, double v) : type(t), value(v) {}
};

class ReactorEngine {
    double temperature = 300.0;
    double pressure = 100.0;

public:
    void execute(const std::vector<OpCode>& instructions) {
        for (size_t i = 0; i < instructions.size(); ++i) {
            const OpCode& op = instructions[i];
            
            switch (op.type) {
                case INJECT:
                    pressure += op.value;
                    temperature += (op.value * 0.5);
                    std::cout << "Inyectando. Presion: " << pressure << "\n";
                    break;
                case CHECK_TEMP:
                    if (temperature > op.value) {
                         std::cout << "ALERTA: Temperatura critica!\n";
                         temperature -= 10.0; 
                    }
                    break;
                case LOOP:
                    std::cout << "Ejecutando bucle " << op.value << " veces...\n";
                    break;
            }
        }
    }
};

int main() {
    // Programa simple
    std::vector<OpCode> programa;
    programa.push_back(OpCode(INJECT, 1.0));
    programa.push_back(OpCode(CHECK_TEMP, 500000.0));

    ReactorEngine motor;
    

    for(int i=0; i<500000; i++) {
        motor.execute(programa);
    }
    
    return 0;
}
