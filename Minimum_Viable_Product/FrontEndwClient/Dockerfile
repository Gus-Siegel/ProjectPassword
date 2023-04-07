FROM python:3.10-slim

WORKDIR /app

#install packages
RUN apt-get update -y
RUN apt-get install tk -y

#copy in necessary files
COPY gui_v3.0.py .
COPY logo.png .
COPY socket_clientV3.py .

#install dependencies
RUN pip install --upgrade pip
RUN pip install requests
RUN pip install xauth
#RUN pip install x11-utils


EXPOSE 5500

CMD ["python", "gui_v3.0.py"]