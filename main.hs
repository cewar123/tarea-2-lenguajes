{-# LANGUAGE BangPatterns #-} 

import Control.Monad (replicateM_)
import Data.List (foldl')

-- Definición estricta de datos (con !)
data Reactor = Reactor { 
    temp :: !Double, 
    presion :: !Double 
} deriving (Show)

data Instruccion 
    = Inject !Double 
    | CheckTemp !Double 
    | Loop !Int 

-- Lógica de un paso
step :: Reactor -> Instruccion -> Reactor
step r (Inject c) = r { presion = presion r + c, temp = temp r + (c * 0.5) }
step r (CheckTemp l) = if temp r > l then r { temp = temp r - 10.0 } else r
step r (Loop _) = r 

-- Ejecutor de programa
ejecutarPrograma :: Reactor -> [Instruccion] -> Reactor
ejecutarPrograma r insts = foldl' step r insts

-- Bucle recursivo
bucleGigante :: Int -> Reactor -> [Instruccion] -> Reactor
bucleGigante 0 r _ = r
bucleGigante n r prog = 
    let !nuevoReactor = ejecutarPrograma r prog
    in bucleGigante (n-1) nuevoReactor prog

main :: IO ()
main = do
    putStrLn "--- Iniciando Haskell (500,000 ciclos) ---"
    
    let reactorInicial = Reactor 300.0 100.0
    let programa = [Inject 1.0, CheckTemp 500000.0]
    
    let resultadoFinal = bucleGigante 500000 reactorInicial programa
    
    print resultadoFinal