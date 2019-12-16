import requests
import json


def send_message(message : str, url: str) -> None:
    headers = {"Content-Type": "application/json"}
    response = requests.post(url, json={"text": message}, headers=headers)

    if response.status_code != 200:
        raise ValueError (
            f"Request to slack returned an error {response.status_code},"
            f"the response is:\n{response.text}"
        )

def main():

    slack_url = "https://hooks.slack.com/services/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"
    message = "My first message to slack channel"

    send_message(message, slack_url)

if __name__ == "__main__":
    main()