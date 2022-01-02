# Problem
## Border Security System
In an imaginary world, every country wants to deploy a border security system (BSS). Main controller of BSS will be deployed in capital city of the country. A sensing cable will go straight to nearest border. The sensing cable will then installed along border surrounding country and come back to capital. 

You will be provided two files: one that contains borders of countries as a polygon in geojson format (countries.geojson) and one that contains the coordinates of the capital cities of countries (capitals.geojson).

You are asked to:
1. Calculate length of border of countries.
2. Calculate length of sensing cable.
in json format.

## Application
* Application shoule be named "bss" case sensitive.
* Application should be written in C++.
* Application may use any version of C++ (98,11,14,17) as long as instructions for compilation and/or project management files (cmake/make/VS Project) are provided.
* Application should be a console application.
* Application should be given command line arguments
* Application may use third party libraries.
* Application should output length of borders of all possible (countries) if command line arguments are not provided.
* Application should read border and capital files from same directory application runs.
* Application should output to standard console output (i.e. std::cout)
* Application should provide meaningful error messages ot standard error output (i.e. std::cerr)

## Interfaces
### Command line arguments
| command line option      |  description     |  argument     |
|  ---  |  ---  |  ---  |
|   -c    | country of interest. Default: All      | ISO Alpha 3 Code      |
|   -t    | type of calculation. Default: border      | "border" or "cable"  |


#### Examples

1. Calculate border of Azerbaijan
```
bss -c AZE -t border
```
2. Calculate sensing cable length of Bulgaria
```
bss -c BGR -t cable
```
3. Calculate border length of all countries
```
bss
```

### Output
Output of calculation should be in json format. Pretty printing is not important. It should be in legal json format. 

<b style="color:red">Note:</b> Calculations in examples are not correct.

#### Examples
1. Calculate border of Azerbaijan
```json
[
    {
        "name": "Azerbaijan",
        "iso_a3": "AZE",
        "border": 2013.0
    }
]
```
| Field      | Description      |
|  ---  |  ---  |
| name      | name of country (as in countries.geojson)      |
| iso_a3      | iso alpha 3 code (as in countries.geojson)      |
| border      | calculated length of border in kilometers     |

2. Calculate sensing cable length of Bulgaria
```json
[
    {
        "name": "Azerbaijan",
        "iso_a3": "AZE",
        "cable": 2050.6
    }
]
```
| Field      | Description      |
|  ---  |  ---  |
| name      | name of country (as in countries.geojson)      |
| iso_a3      | iso alpha 3 code (as in countries.geojson)      |
| cable      | calculated length of sensing cable in kilometers     |


3. Calculate border length of all countries
```json
[
    {
        "name": "Aruba",
        "iso_a3": "ABW",
        "cable": 500.2
    },
    {
        "name": "Afghanistan",
        "iso_a3": "AFG",
        "cable": 5529.0
    },{
        "name": "Angola",
        "iso_a3": "AGO",
        "cable": 5198.0
    },
    ...
]
```

# Turn-in Instructions
Please commit your application code to [GitHub](https://www.github.com) and share the link.
