#!/bin/python
############################################################
# Looking for enem keyword to write a file with tweets
# Autohor: Delermando
# Doctorate program - UFES
#
###########################################################

# Import the necessary methods from tweepy library
from tweepy.streaming import StreamListener
from tweepy import OAuthHandler
from tweepy import Stream

#Variables that contains the user credentials to access Twitter API 
access_token = "2491740482-ysPmPw6hNbU6WupdTQ5hWdkT8tcUAr843KJyXsE"
access_token_secret = "AmkTO5S28B313e1gVA7OhpbTUWe6DXagVshZXBIrz8SOo"
consumer_key = "dyJ0urEwsZhIQxMJr4E1iXqZl"
consumer_secret = "lkKgqT1CU8WsDiD3o381RArJUvxfwocNNEnlHHYqYY49GE6Nbi"


#This is a basic listener that just prints received tweets to stdout.
class StdOutListener(StreamListener):

    def on_data(self, data):
        print data
        return True

    def on_error(self, status):
        print status


if __name__ == '__main__':

    #This handles Twitter authetification and the connection to Twitter Streaming API
    l = StdOutListener()
    auth = OAuthHandler(consumer_key, consumer_secret)
    auth.set_access_token(access_token, access_token_secret)
    stream = Stream(auth, l)

    #This line filter Twitter Streams to capture data by the keywords in track filter
    stream.filter(track=['enem'])

