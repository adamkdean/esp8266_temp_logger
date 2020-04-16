#  __ __  __   __  __   __   __
# |_ (__ |__) (__)  _) /__  /__
# |__ __)|    (__) /__ \__) \__)
#
# (C) Copyright 2020 Adam K Dean

FROM node:lts
MAINTAINER Adam K Dean <adamkdean@googlemail.com>

WORKDIR /www

COPY package*.json ./
RUN npm install --only=production

COPY server.js /www

CMD ["npm", "start"]
