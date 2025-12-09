
enum Instruccion {
    Inject(f64),      // Inyectar cantidad
    CheckTemp(f64),   // Revisar si temperatura > límite
    Loop(u32),        // Repetir X veces
}

struct MotorReactor {
    temperatura: f64,
    presion: f64,
}

impl MotorReactor {
    // Constructor para iniciar valores
    fn nuevo() -> Self {
        MotorReactor {
            temperatura: 300.0,
            presion: 100.0,
        }
    }

    fn ejecutar(&mut self, programa: &[Instruccion]) {
        for instruccion in programa {
            match instruccion {
                Instruccion::Inject(cantidad) => {
                    self.presion += cantidad;
                    self.temperatura += cantidad * 0.5;
                    println!("-> Inyectando. Presion actual: {:.2}", self.presion);
                }
                Instruccion::CheckTemp(limite) => {
                    if self.temperatura > *limite {
                        println!("ALERTA: Temperatura crítica ({:.2}). Enfriando...", self.temperatura);
                        self.temperatura -= 10.0;
                    }
                }
                Instruccion::Loop(veces) => {
                    println!("-> Ejecutando bucle de mantenimiento {} veces", veces);
                }
            }
        }
    }
}

fn main() {
    let mut motor = MotorReactor::nuevo();
    // Programa simple
    let programa = vec![
        Instruccion::Inject(1.0),
        Instruccion::CheckTemp(500000.0),
    ];

    for _ in 0..500_000 {
        motor.ejecutar(&programa);
    }
}