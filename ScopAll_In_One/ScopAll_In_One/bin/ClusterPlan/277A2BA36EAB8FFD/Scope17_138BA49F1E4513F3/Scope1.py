'''
  The following is a sample Python UDO.
  Details on Python UDOs: https://microsoft.sharepoint.com/:w:/r/teams/Cosmos/_layouts/15/Doc.aspx?sourcedoc=%7B7E714159-3C83-4822-A357-B44503EF0C80%7D&file=Scope_Python%20UDO%20Extenstion.docx&action=default&mobileredirect=true&DefaultItemOpen=1&cid=e5947e3b-6d54-429b-a1bf-eb226be1a3cf
'''

class DataFrameDemoReducer:
    def __init__(self):
        self.pyadlahelper = __import__('pyadlahelper')
        pass

    def Reduce(self, inputRowset, outputRow):
        df = self.pyadlahelper.RowsetToDataframe(inputRowset, -1)
        outputRow['Name'] = inputRowset.Key['Name']
        outputRow['Count'] = len(df)
        distribution = df.describe()
        outputRow['SepalLength_Mean'] = round(distribution['SepalLength']['mean'], 2)
        outputRow['SepalWidth_Mean'] = round(distribution['SepalWidth']['mean'], 2)
        outputRow['PetalLength_Mean'] = round(distribution['PetalLength']['mean'], 2)
        outputRow['PetalWidth_Mean'] = round(distribution['PetalWidth']['mean'], 2)
        yield outputRow


class SearchLogExtractor:
    def __init__(self):
        pass

    def Extract(self, rawInput, outputRow):
        stream = rawInput.GetBaseStream
        bufferToRead = bytearray(100 * 1024 * 1024)
        numBytesRead = stream.readinto(bufferToRead)
        if numBytesRead == len(bufferToRead):
            raise RuntimeError('input stream is too big')

        for row in bufferToRead[:numBytesRead].decode('utf-8').split('\r\n'):
            for columnIndex, columnValue in enumerate(row.split('\t')):
                columnType = outputRow.Schema[columnIndex].Type
                outputRow[columnIndex] = columnType(columnValue)

            yield outputRow



			