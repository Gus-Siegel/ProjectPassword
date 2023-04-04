FROM python:3.10-slim

WORKDIR /app

#install packages
RUN apt-get update && apt-get install -y tk

#copy in necessary files
COPY gui_v3.0.py .
COPY logo.png .
COPY socket_clientV3.py .

#install dependencies
RUN pip install requests

EXPOSE 5500

CMD ["python", "gui_v3.0.py"]