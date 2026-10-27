# Protocolul de Comunicație UART

Documentația detaliată a schimbului de mesaje pe portul serial între PC (gazdă) și plăcuța Arduino.

## 1. Diagramă de secvență și schimb de mesaje

```mermaid
sequenceDiagram
    autonumber
    actor PC as PC / Serial Monitor
    participant MCU as Arduino Uno
    
    PC->>MCU: START
    MCU-->>PC: ACK (Comandă primită)
    loop Eșantionare continuă
        MCU->>PC: timestamp_ms, raw_adc, voltage_v, temp_c
    end
    PC->>MCU: STOP
    MCU-->>PC: ACK (Achiziție oprită)
```

## 2. Setul de comenzi suportate

| Comandă | Cod ASCII | Efect produs |
| :--- | :---: | :--- |
| `START` | `0x01` | Inițiază achiziția și transmiterea datelor la intervale fixe |
| `STOP`  | `0x02` | Oprește transmiterea cadrelor pe interfața serială |
| `STATUS`| `0x03` | Returnează starea curentă a sistemului și numărul de eșantioane |

## 3. Automatul de stări al sistemului

```mermaid
stateDiagram-v2
    [*] --> IDLE
    
    IDLE --> SAMPLING : Primire comanda START / Apasare buton
    SAMPLING --> IDLE : Primire comanda STOP / Apasare buton
    
    SAMPLING --> ALARM : T_medie > Prag_Max (ex. 50°C)
    ALARM --> SAMPLING : T_medie <= Prag_Max
    ALARM --> IDLE : Primire comanda STOP


    ## 4. Automatul de stări (State Machine)
Sistemul de achiziție funcționează pe baza a 3 stări principale:

```mermaid
stateDiagram-v2
    [*] --> IDLE
    IDLE --> SAMPLING : Comandă START
    SAMPLING --> IDLE : Comandă STOP
    SAMPLING --> ALARM : Temperatură > Prag (ex: 45°C)
    ALARM --> SAMPLING : Scădere sub prag
    ALARM --> IDLE : Comandă STOP
```
