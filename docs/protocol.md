# Protocolul de Comunicație Serială

## 1. Prezentare generală
Acest document descrie schimbul de mesaje prin portul serial între unitatea de achiziție (Arduino) și calculator (PC).

## 2. Diagramă de secvență
Diagrama de mai jos ilustrează inițierea achiziției:

```mermaid
sequenceDiagram
    participant PC
    participant Arduino
    PC->>Arduino: START
    Arduino-->>PC: ACK (Sistem pornit)
    loop Eșantionare
        Arduino->>PC: timestamp, adc, voltage, temp
    end