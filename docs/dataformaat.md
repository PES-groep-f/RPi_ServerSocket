# Dataformaat

Header | Lengte  (bits) | Omschrijving
|-|-|-|
messageId | 8 | Komt overeen met 7-bit I2C message IDs
Vector lengte | 4 | Geeft aan hoeveel data-elementen er in dit bericht zitten (bijvoorbeeld 3 voor een RGB lamp aansturing)
Datatype | 4 | Enum veld, voor waardes zie het kopje Datatypes
Data | Variabel | 

## Datatypes

- 0: uint32 (4 bytes)
- 1: int32 (4 bytes)
- 2: float (4 bytes)
- 3: boolean (1 byte)
- 4: ASCII string, null terminated (variabele lengte)
- 5: uint8 (1 byte)

*Noot: als het gaat om een ASCII string is de vector lengte altijd 1.*

## Voorbeeldberichten

De kleur geel (voor RGB lampen):

Message ID | Vector Length | Datatype | Data
|-|-|-|-|
27   | 3 | 5=uint8 | 255 213 0

Luchtvochtigheid

Message ID | Vector Length | Datatype | Data
|-|-|-|-|
148   | 1 | float | 82.58294582
