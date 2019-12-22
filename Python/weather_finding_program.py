import requests
import json
import decimal


def main():

    api_key = "0901ee64fbf48c56803045f578ff5eb1"

    base_url = "http://api.openweathermap.org/data/2.5/weather?"

    city_name = input("Enter city name: ")

    complete_url = base_url + "appid=" + api_key + "&q=" + city_name

    response = requests.get(complete_url)

    json_file = response.json()

    if json_file["cod"] != "404":
        holder = json_file["main"]

        current_temperature = holder["temp"]

        print(f"Temperate in Celsius: {round(300 - current_temperature)}")

        current_pressure = holder["pressure"]

        print(f"Atmospheric pressure (in hPa unit): {current_pressure}")

        current_humidity = holder["humidity"]

        print(f"Humidity: {current_humidity}")

        weather_description = json_file["weather"][0]["description"]

        print(f"Weather description: {weather_description}")

    else:
        print("City Not Found")


if __name__ == "__main__":
    main()