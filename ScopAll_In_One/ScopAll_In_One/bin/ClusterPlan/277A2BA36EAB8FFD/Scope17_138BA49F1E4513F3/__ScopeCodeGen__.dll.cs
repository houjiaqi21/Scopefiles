using Microsoft.Analytics.Interfaces;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Text;
using System.Reflection;
using System.IO;
using System.Text.RegularExpressions;
using System.Threading;
using System.Runtime.Serialization;
using System.Linq;
using Microsoft.SCOPE.Types;
using ScopeRuntime;
using Privacy;
using System.Runtime.Versioning;
[assembly:TargetFramework(".NETFramework,Version=v4.7.2", FrameworkDisplayName = ".NET Framework, Version 4.7.2")]

public class ___Scope_Generated_Classes___
{
	public static int __RuntimeVersion__ = 0;
	public static int __WriteSStreamVersion__ = 3;
	public static bool __BondIntermediates__ = false;
	private delegate ColumnData ColumnDataCtor();
#region ==BEGIN USER CODE==
public class FreqProcessor : Processor
{
    /// <summary>
    /// 
    /// </summary>
    /// <param name="columns"></param>
    /// <param name="args"></param>
    /// <param name="input"></param>
    /// <returns></returns>
    public override Schema Produces(string[] columns, string[] args, Schema input)
    {
        return new Schema("BingAdsUserId:int, MsAlias:string,UcmUserId:int,FreqSegment:string,NumofMonth:int,LastMonth:string,NumofWeek:int,TotalUsage:int");
    }
    /// <summary>
    ///
    /// </summary>
    /// <param name="input"></param>
    /// <param name="output"></param>
    /// <param name="args"></param>
    /// <returns></returns>    
    public override IEnumerable<Row> Process(RowSet input, Row output, string[] args)
    {
        string mm = args[0];
        int w = Convert.ToInt32(args[1]); 
        int m = Convert.ToInt32(args[2]);

        int BingAdsUserId = 0;
        string MsAlias = string.Empty;
        int UcmUserId = 0;
        string FreqSegment = string.Empty;
        int NumofMonth = 0;
        string LastMonth = string.Empty;
        int NumofWeek = 0;
        int TotalUsage = 0;
        foreach (Row row in input.Rows)
        {
            BingAdsUserId = row["BingAdsUserId"].Integer;
            MsAlias = row["MsAlias"].String;
            UcmUserId = row["UcmUserId"].Integer;
            NumofMonth = row["NumofMonth"].Integer;
            LastMonth = row["LastMonth"].String;
            NumofWeek = row["NumofWeek"].Integer;
            TotalUsage = row["TotalUsage"].Integer;
            if (NumofWeek == w)
            {
                FreqSegment = @"Fans User";
            }
            else if (NumofMonth == m)
            {
                FreqSegment = @"Stable User";
            }
            else if (NumofMonth == 1 && LastMonth == mm)
            {
                FreqSegment = @"New User";
            }
            else if (NumofWeek == -1 && NumofMonth == -1 && LastMonth == "Non")
            {
                FreqSegment = @"Non User";
            }
            else FreqSegment = @"Swing User";
            output["BingAdsUserId"].Set(BingAdsUserId);
            output["MsAlias"].Set(MsAlias);
            output["UcmUserId"].Set(UcmUserId);
            output["NumofMonth"].Set(NumofMonth);
            output["LastMonth"].Set(LastMonth);
            output["NumofWeek"].Set(NumofWeek);
            output["TotalUsage"].Set(TotalUsage);
            output["FreqSegment"].Set(FreqSegment);
            yield return output;
        }
    }
}

public class MyTsvExtractor : Extractor
{
    public override Schema Produces(string[] requested_columns, string[] args)
    {
        return new Schema(requested_columns);
    }

    public override IEnumerable<Row> Extract(StreamReader reader, Row output_row, string[] args)
    {
        char delimiter = '\t';
        string line;

        int debug_count = 0;

        while ((line = reader.ReadLine()) != null)
        {
            var tokens = line.Split(delimiter);
            for (int i = 0; i < tokens.Length; ++i)
            {
                output_row[i].UnsafeSet(tokens[i]);
            }

            string debug_msg = string.Format("Line {0}: {1}", debug_count, line.Trim());
            ScopeRuntime.Diagnostics.DebugStream.WriteLine(debug_msg);

            debug_count++;

            yield return output_row;
        }
    }
}

public class MySum_Integer : Aggregate1<int, int>
{
    int sum = 0;

    public override void Initialize()
    {
        sum = 0;
    }

    public override void Add(int y)
    {
        sum += y;
    }

    public override int Finalize()
    {
        return sum;
    }
}

#endregion ==END USER CODE==

	public class Row_Column1_String_Column2_String_Column3_String : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Column1", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Column2", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Column3", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.StringColumnData s0_Column1;
		public ScopeRuntime.StringColumnData Column1
		{
			get { return s0_Column1; }
			set 
			{
				s0_Column1 = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Column2;
		public ScopeRuntime.StringColumnData Column2
		{
			get { return s0_Column2; }
			set 
			{
				s0_Column2 = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Column3;
		public ScopeRuntime.StringColumnData Column3
		{
			get { return s0_Column3; }
			set 
			{
				s0_Column3 = value;
				_columns[2] = value;
			}
		}
		public Row_Column1_String_Column2_String_Column3_String(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Column1_String_Column2_String_Column3_String(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Column1_String_Column2_String_Column3_String() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_Column1 = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_Column2 = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_Column3 = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Column1.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Column2.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (s0_Column3.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 3);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_Column1.IsNull())
			{
				s0_Column1.Serialize(writer);
			}
			if (!s0_Column2.IsNull())
			{
				s0_Column2.Serialize(writer);
			}
			if (!s0_Column3.IsNull())
			{
				s0_Column3.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Column1.Deserialize(reader);
				s0_Column2.Deserialize(reader);
				s0_Column3.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_Column1.Deserialize(reader);
				}
				else
				{
					s0_Column1.SetNull();
				}
				if ((___masking___[0] & 4) != 4)
				{
					s0_Column2.Deserialize(reader);
				}
				else
				{
					s0_Column2.SetNull();
				}
				if ((___masking___[0] & 8) != 8)
				{
					s0_Column3.Deserialize(reader);
				}
				else
				{
					s0_Column3.SetNull();
				}
			}
		}
	}

	public class ScopeSStreamOutput_1 : SStreamOutputter
	{
		Row_Column1_String_Column2_String_Column3_String columnGroupRow_0 = new Row_Column1_String_Column2_String_Column3_String (new Schema("Column1:string,Column2:string,Column3:string"));
		public ScopeSStreamOutput_1()
		{
			_isSerial = true;
			_blockSize = 4194304;
		}
		public override void OutputRow (Row row)
		{
			columnGroupRow_0.Column1 = ((Row_Column1_String_Column2_String_Column3_String)row).Column1;
			columnGroupRow_0.Column2 = ((Row_Column1_String_Column2_String_Column3_String)row).Column2;
			columnGroupRow_0.Column3 = ((Row_Column1_String_Column2_String_Column3_String)row).Column3;
			_writers[0].AppendRow (columnGroupRow_0 );
			
		}
	}


	public class Row_BingAdsUserId_Integer_MsAlias_String_UcmUserId_Integer_NumofWeek_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("BingAdsUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("MsAlias", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UcmUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofWeek", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_BingAdsUserId;
		public ScopeRuntime.IntegerColumnData BingAdsUserId
		{
			get { return s0_BingAdsUserId; }
			set 
			{
				s0_BingAdsUserId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_MsAlias;
		public ScopeRuntime.StringColumnData MsAlias
		{
			get { return s0_MsAlias; }
			set 
			{
				s0_MsAlias = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UcmUserId;
		public ScopeRuntime.IntegerColumnData UcmUserId
		{
			get { return s0_UcmUserId; }
			set 
			{
				s0_UcmUserId = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_NumofWeek;
		public ScopeRuntime.IntegerColumnData NumofWeek
		{
			get { return s0_NumofWeek; }
			set 
			{
				s0_NumofWeek = value;
				_columns[3] = value;
			}
		}
		public Row_BingAdsUserId_Integer_MsAlias_String_UcmUserId_Integer_NumofWeek_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_BingAdsUserId_Integer_MsAlias_String_UcmUserId_Integer_NumofWeek_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_BingAdsUserId_Integer_MsAlias_String_UcmUserId_Integer_NumofWeek_Integer() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_BingAdsUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_MsAlias = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_UcmUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 3:
					{
						s0_NumofWeek = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_MsAlias.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_BingAdsUserId.Serialize(writer);
			if (!s0_MsAlias.IsNull())
			{
				s0_MsAlias.Serialize(writer);
			}
			s0_UcmUserId.Serialize(writer);
			s0_NumofWeek.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_BingAdsUserId.Deserialize(reader);
				s0_MsAlias.Deserialize(reader);
				s0_UcmUserId.Deserialize(reader);
				s0_NumofWeek.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_BingAdsUserId.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_MsAlias.Deserialize(reader);
				}
				else
				{
					s0_MsAlias.SetNull();
				}
				s0_UcmUserId.Deserialize(reader);
				s0_NumofWeek.Deserialize(reader);
			}
		}
	}


	public class Row_NumofWeek_Integer_BingAdsUserId1_Integer_MsAlias2_String_UcmUserId3_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofWeek", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("BingAdsUserId1", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("MsAlias2", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UcmUserId3", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_NumofWeek;
		public ScopeRuntime.IntegerColumnData NumofWeek
		{
			get { return s0_NumofWeek; }
			set 
			{
				s0_NumofWeek = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_BingAdsUserId1;
		public ScopeRuntime.IntegerColumnData BingAdsUserId1
		{
			get { return s0_BingAdsUserId1; }
			set 
			{
				s0_BingAdsUserId1 = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_MsAlias2;
		public ScopeRuntime.StringColumnData MsAlias2
		{
			get { return s0_MsAlias2; }
			set 
			{
				s0_MsAlias2 = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UcmUserId3;
		public ScopeRuntime.IntegerColumnData UcmUserId3
		{
			get { return s0_UcmUserId3; }
			set 
			{
				s0_UcmUserId3 = value;
				_columns[3] = value;
			}
		}
		public Row_NumofWeek_Integer_BingAdsUserId1_Integer_MsAlias2_String_UcmUserId3_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_NumofWeek_Integer_BingAdsUserId1_Integer_MsAlias2_String_UcmUserId3_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_NumofWeek_Integer_BingAdsUserId1_Integer_MsAlias2_String_UcmUserId3_Integer() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_NumofWeek = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_BingAdsUserId1 = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 2:
					{
						s0_MsAlias2 = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 3:
					{
						s0_UcmUserId3 = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_MsAlias2.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_NumofWeek.Serialize(writer);
			s0_BingAdsUserId1.Serialize(writer);
			if (!s0_MsAlias2.IsNull())
			{
				s0_MsAlias2.Serialize(writer);
			}
			s0_UcmUserId3.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_NumofWeek.Deserialize(reader);
				s0_BingAdsUserId1.Deserialize(reader);
				s0_MsAlias2.Deserialize(reader);
				s0_UcmUserId3.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_NumofWeek.Deserialize(reader);
				s0_BingAdsUserId1.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_MsAlias2.Deserialize(reader);
				}
				else
				{
					s0_MsAlias2.SetNull();
				}
				s0_UcmUserId3.Deserialize(reader);
			}
		}
	}


	public class Row_998E3C0B90688B36 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("BingAdsUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("MsAlias", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UcmUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofMonth", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("LastMonth", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("TotalUsage", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofWeek", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_BingAdsUserId;
		public ScopeRuntime.IntegerColumnData BingAdsUserId
		{
			get { return s0_BingAdsUserId; }
			set 
			{
				s0_BingAdsUserId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_MsAlias;
		public ScopeRuntime.StringColumnData MsAlias
		{
			get { return s0_MsAlias; }
			set 
			{
				s0_MsAlias = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UcmUserId;
		public ScopeRuntime.IntegerColumnData UcmUserId
		{
			get { return s0_UcmUserId; }
			set 
			{
				s0_UcmUserId = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_NumofMonth;
		public ScopeRuntime.IntegerColumnData NumofMonth
		{
			get { return s0_NumofMonth; }
			set 
			{
				s0_NumofMonth = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_LastMonth;
		public ScopeRuntime.StringColumnData LastMonth
		{
			get { return s0_LastMonth; }
			set 
			{
				s0_LastMonth = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_TotalUsage;
		public ScopeRuntime.IntegerColumnData TotalUsage
		{
			get { return s0_TotalUsage; }
			set 
			{
				s0_TotalUsage = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_NumofWeek;
		public ScopeRuntime.IntegerColumnData NumofWeek
		{
			get { return s0_NumofWeek; }
			set 
			{
				s0_NumofWeek = value;
				_columns[6] = value;
			}
		}
		public Row_998E3C0B90688B36(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_998E3C0B90688B36(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_998E3C0B90688B36() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_BingAdsUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_MsAlias = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_UcmUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 3:
					{
						s0_NumofMonth = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 4:
					{
						s0_LastMonth = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 5:
					{
						s0_TotalUsage = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 6:
					{
						s0_NumofWeek = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_MsAlias.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_LastMonth.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_BingAdsUserId.Serialize(writer);
			if (!s0_MsAlias.IsNull())
			{
				s0_MsAlias.Serialize(writer);
			}
			s0_UcmUserId.Serialize(writer);
			s0_NumofMonth.Serialize(writer);
			if (!s0_LastMonth.IsNull())
			{
				s0_LastMonth.Serialize(writer);
			}
			s0_TotalUsage.Serialize(writer);
			s0_NumofWeek.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_BingAdsUserId.Deserialize(reader);
				s0_MsAlias.Deserialize(reader);
				s0_UcmUserId.Deserialize(reader);
				s0_NumofMonth.Deserialize(reader);
				s0_LastMonth.Deserialize(reader);
				s0_TotalUsage.Deserialize(reader);
				s0_NumofWeek.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_BingAdsUserId.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_MsAlias.Deserialize(reader);
				}
				else
				{
					s0_MsAlias.SetNull();
				}
				s0_UcmUserId.Deserialize(reader);
				s0_NumofMonth.Deserialize(reader);
				if ((___masking___[0] & 4) != 4)
				{
					s0_LastMonth.Deserialize(reader);
				}
				else
				{
					s0_LastMonth.SetNull();
				}
				s0_TotalUsage.Deserialize(reader);
				s0_NumofWeek.Deserialize(reader);
			}
		}
	}


	public class Row_89729CEF5E65DC47 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofMonth", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("LastMonth", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("TotalUsage", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofWeek", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("BingAdsUserId1", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("MsAlias2", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UcmUserId3", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_NumofMonth;
		public ScopeRuntime.IntegerColumnData NumofMonth
		{
			get { return s0_NumofMonth; }
			set 
			{
				s0_NumofMonth = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_LastMonth;
		public ScopeRuntime.StringColumnData LastMonth
		{
			get { return s0_LastMonth; }
			set 
			{
				s0_LastMonth = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_TotalUsage;
		public ScopeRuntime.IntegerColumnData TotalUsage
		{
			get { return s0_TotalUsage; }
			set 
			{
				s0_TotalUsage = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_NumofWeek;
		public ScopeRuntime.IntegerColumnData NumofWeek
		{
			get { return s0_NumofWeek; }
			set 
			{
				s0_NumofWeek = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_BingAdsUserId1;
		public ScopeRuntime.IntegerColumnData BingAdsUserId1
		{
			get { return s0_BingAdsUserId1; }
			set 
			{
				s0_BingAdsUserId1 = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_MsAlias2;
		public ScopeRuntime.StringColumnData MsAlias2
		{
			get { return s0_MsAlias2; }
			set 
			{
				s0_MsAlias2 = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UcmUserId3;
		public ScopeRuntime.IntegerColumnData UcmUserId3
		{
			get { return s0_UcmUserId3; }
			set 
			{
				s0_UcmUserId3 = value;
				_columns[6] = value;
			}
		}
		public Row_89729CEF5E65DC47(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_89729CEF5E65DC47(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_89729CEF5E65DC47() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_NumofMonth = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_LastMonth = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_TotalUsage = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 3:
					{
						s0_NumofWeek = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 4:
					{
						s0_BingAdsUserId1 = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 5:
					{
						s0_MsAlias2 = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 6:
					{
						s0_UcmUserId3 = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_LastMonth.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_MsAlias2.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_NumofMonth.Serialize(writer);
			if (!s0_LastMonth.IsNull())
			{
				s0_LastMonth.Serialize(writer);
			}
			s0_TotalUsage.Serialize(writer);
			s0_NumofWeek.Serialize(writer);
			s0_BingAdsUserId1.Serialize(writer);
			if (!s0_MsAlias2.IsNull())
			{
				s0_MsAlias2.Serialize(writer);
			}
			s0_UcmUserId3.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_NumofMonth.Deserialize(reader);
				s0_LastMonth.Deserialize(reader);
				s0_TotalUsage.Deserialize(reader);
				s0_NumofWeek.Deserialize(reader);
				s0_BingAdsUserId1.Deserialize(reader);
				s0_MsAlias2.Deserialize(reader);
				s0_UcmUserId3.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_NumofMonth.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_LastMonth.Deserialize(reader);
				}
				else
				{
					s0_LastMonth.SetNull();
				}
				s0_TotalUsage.Deserialize(reader);
				s0_NumofWeek.Deserialize(reader);
				s0_BingAdsUserId1.Deserialize(reader);
				if ((___masking___[0] & 4) != 4)
				{
					s0_MsAlias2.Deserialize(reader);
				}
				else
				{
					s0_MsAlias2.SetNull();
				}
				s0_UcmUserId3.Deserialize(reader);
			}
		}
	}


	public class Row_EF2C5448D032F8E2 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("BingAdsUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("MsAlias", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UcmUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofMonth", ScopeRuntime.ColumnDataType.IntegerQ, typeof(System.Int32?), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("LastMonth", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("TotalUsage", ScopeRuntime.ColumnDataType.IntegerQ, typeof(System.Int32?), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofWeek", ScopeRuntime.ColumnDataType.IntegerQ, typeof(System.Int32?), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_BingAdsUserId;
		public ScopeRuntime.IntegerColumnData BingAdsUserId
		{
			get { return s0_BingAdsUserId; }
			set 
			{
				s0_BingAdsUserId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_MsAlias;
		public ScopeRuntime.StringColumnData MsAlias
		{
			get { return s0_MsAlias; }
			set 
			{
				s0_MsAlias = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UcmUserId;
		public ScopeRuntime.IntegerColumnData UcmUserId
		{
			get { return s0_UcmUserId; }
			set 
			{
				s0_UcmUserId = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.IntegerQColumnData s0_NumofMonth;
		public ScopeRuntime.IntegerQColumnData NumofMonth
		{
			get { return s0_NumofMonth; }
			set 
			{
				s0_NumofMonth = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_LastMonth;
		public ScopeRuntime.StringColumnData LastMonth
		{
			get { return s0_LastMonth; }
			set 
			{
				s0_LastMonth = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.IntegerQColumnData s0_TotalUsage;
		public ScopeRuntime.IntegerQColumnData TotalUsage
		{
			get { return s0_TotalUsage; }
			set 
			{
				s0_TotalUsage = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.IntegerQColumnData s0_NumofWeek;
		public ScopeRuntime.IntegerQColumnData NumofWeek
		{
			get { return s0_NumofWeek; }
			set 
			{
				s0_NumofWeek = value;
				_columns[6] = value;
			}
		}
		public Row_EF2C5448D032F8E2(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_EF2C5448D032F8E2(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_EF2C5448D032F8E2() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_BingAdsUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_MsAlias = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_UcmUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 3:
					{
						s0_NumofMonth = (ScopeRuntime.IntegerQColumnData)value;
						break;
					}
					case 4:
					{
						s0_LastMonth = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 5:
					{
						s0_TotalUsage = (ScopeRuntime.IntegerQColumnData)value;
						break;
					}
					case 6:
					{
						s0_NumofWeek = (ScopeRuntime.IntegerQColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_MsAlias.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_NumofMonth.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (s0_LastMonth.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 3);
			}
			if (s0_TotalUsage.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 4);
			}
			if (s0_NumofWeek.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 5);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_BingAdsUserId.Serialize(writer);
			if (!s0_MsAlias.IsNull())
			{
				s0_MsAlias.Serialize(writer);
			}
			s0_UcmUserId.Serialize(writer);
			if (!s0_NumofMonth.IsNull())
			{
				s0_NumofMonth.Serialize(writer);
			}
			if (!s0_LastMonth.IsNull())
			{
				s0_LastMonth.Serialize(writer);
			}
			if (!s0_TotalUsage.IsNull())
			{
				s0_TotalUsage.Serialize(writer);
			}
			if (!s0_NumofWeek.IsNull())
			{
				s0_NumofWeek.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_BingAdsUserId.Deserialize(reader);
				s0_MsAlias.Deserialize(reader);
				s0_UcmUserId.Deserialize(reader);
				s0_NumofMonth.Deserialize(reader);
				s0_LastMonth.Deserialize(reader);
				s0_TotalUsage.Deserialize(reader);
				s0_NumofWeek.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_BingAdsUserId.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_MsAlias.Deserialize(reader);
				}
				else
				{
					s0_MsAlias.SetNull();
				}
				s0_UcmUserId.Deserialize(reader);
				if ((___masking___[0] & 4) != 4)
				{
					s0_NumofMonth.Deserialize(reader);
				}
				else
				{
					s0_NumofMonth.SetNull();
				}
				if ((___masking___[0] & 8) != 8)
				{
					s0_LastMonth.Deserialize(reader);
				}
				else
				{
					s0_LastMonth.SetNull();
				}
				if ((___masking___[0] & 16) != 16)
				{
					s0_TotalUsage.Deserialize(reader);
				}
				else
				{
					s0_TotalUsage.SetNull();
				}
				if ((___masking___[0] & 32) != 32)
				{
					s0_NumofWeek.Deserialize(reader);
				}
				else
				{
					s0_NumofWeek.SetNull();
				}
			}
		}
	}


	public class Row_B9EB911547BD5731 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofMonth", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("LastMonth", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofWeek", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("TotalUsage", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("BingAdsUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("MsAlias", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UcmUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_NumofMonth;
		public ScopeRuntime.IntegerColumnData NumofMonth
		{
			get { return s0_NumofMonth; }
			set 
			{
				s0_NumofMonth = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_LastMonth;
		public ScopeRuntime.StringColumnData LastMonth
		{
			get { return s0_LastMonth; }
			set 
			{
				s0_LastMonth = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_NumofWeek;
		public ScopeRuntime.IntegerColumnData NumofWeek
		{
			get { return s0_NumofWeek; }
			set 
			{
				s0_NumofWeek = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_TotalUsage;
		public ScopeRuntime.IntegerColumnData TotalUsage
		{
			get { return s0_TotalUsage; }
			set 
			{
				s0_TotalUsage = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_BingAdsUserId;
		public ScopeRuntime.IntegerColumnData BingAdsUserId
		{
			get { return s0_BingAdsUserId; }
			set 
			{
				s0_BingAdsUserId = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_MsAlias;
		public ScopeRuntime.StringColumnData MsAlias
		{
			get { return s0_MsAlias; }
			set 
			{
				s0_MsAlias = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UcmUserId;
		public ScopeRuntime.IntegerColumnData UcmUserId
		{
			get { return s0_UcmUserId; }
			set 
			{
				s0_UcmUserId = value;
				_columns[6] = value;
			}
		}
		public Row_B9EB911547BD5731(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_B9EB911547BD5731(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_B9EB911547BD5731() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_NumofMonth = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_LastMonth = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_NumofWeek = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 3:
					{
						s0_TotalUsage = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 4:
					{
						s0_BingAdsUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 5:
					{
						s0_MsAlias = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 6:
					{
						s0_UcmUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_LastMonth.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_MsAlias.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_NumofMonth.Serialize(writer);
			if (!s0_LastMonth.IsNull())
			{
				s0_LastMonth.Serialize(writer);
			}
			s0_NumofWeek.Serialize(writer);
			s0_TotalUsage.Serialize(writer);
			s0_BingAdsUserId.Serialize(writer);
			if (!s0_MsAlias.IsNull())
			{
				s0_MsAlias.Serialize(writer);
			}
			s0_UcmUserId.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_NumofMonth.Deserialize(reader);
				s0_LastMonth.Deserialize(reader);
				s0_NumofWeek.Deserialize(reader);
				s0_TotalUsage.Deserialize(reader);
				s0_BingAdsUserId.Deserialize(reader);
				s0_MsAlias.Deserialize(reader);
				s0_UcmUserId.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_NumofMonth.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_LastMonth.Deserialize(reader);
				}
				else
				{
					s0_LastMonth.SetNull();
				}
				s0_NumofWeek.Deserialize(reader);
				s0_TotalUsage.Deserialize(reader);
				s0_BingAdsUserId.Deserialize(reader);
				if ((___masking___[0] & 4) != 4)
				{
					s0_MsAlias.Deserialize(reader);
				}
				else
				{
					s0_MsAlias.SetNull();
				}
				s0_UcmUserId.Deserialize(reader);
			}
		}
	}


	public class Row_2AA7BDBB31C1E23B : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("BingAdsUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("MsAlias", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UcmUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofMonth", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("LastMonth", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofWeek", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("TotalUsage", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_BingAdsUserId;
		public ScopeRuntime.IntegerColumnData BingAdsUserId
		{
			get { return s0_BingAdsUserId; }
			set 
			{
				s0_BingAdsUserId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_MsAlias;
		public ScopeRuntime.StringColumnData MsAlias
		{
			get { return s0_MsAlias; }
			set 
			{
				s0_MsAlias = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UcmUserId;
		public ScopeRuntime.IntegerColumnData UcmUserId
		{
			get { return s0_UcmUserId; }
			set 
			{
				s0_UcmUserId = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_NumofMonth;
		public ScopeRuntime.IntegerColumnData NumofMonth
		{
			get { return s0_NumofMonth; }
			set 
			{
				s0_NumofMonth = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_LastMonth;
		public ScopeRuntime.StringColumnData LastMonth
		{
			get { return s0_LastMonth; }
			set 
			{
				s0_LastMonth = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_NumofWeek;
		public ScopeRuntime.IntegerColumnData NumofWeek
		{
			get { return s0_NumofWeek; }
			set 
			{
				s0_NumofWeek = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_TotalUsage;
		public ScopeRuntime.IntegerColumnData TotalUsage
		{
			get { return s0_TotalUsage; }
			set 
			{
				s0_TotalUsage = value;
				_columns[6] = value;
			}
		}
		public Row_2AA7BDBB31C1E23B(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_2AA7BDBB31C1E23B(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_2AA7BDBB31C1E23B() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_BingAdsUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_MsAlias = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_UcmUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 3:
					{
						s0_NumofMonth = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 4:
					{
						s0_LastMonth = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 5:
					{
						s0_NumofWeek = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 6:
					{
						s0_TotalUsage = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_MsAlias.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_LastMonth.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_BingAdsUserId.Serialize(writer);
			if (!s0_MsAlias.IsNull())
			{
				s0_MsAlias.Serialize(writer);
			}
			s0_UcmUserId.Serialize(writer);
			s0_NumofMonth.Serialize(writer);
			if (!s0_LastMonth.IsNull())
			{
				s0_LastMonth.Serialize(writer);
			}
			s0_NumofWeek.Serialize(writer);
			s0_TotalUsage.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_BingAdsUserId.Deserialize(reader);
				s0_MsAlias.Deserialize(reader);
				s0_UcmUserId.Deserialize(reader);
				s0_NumofMonth.Deserialize(reader);
				s0_LastMonth.Deserialize(reader);
				s0_NumofWeek.Deserialize(reader);
				s0_TotalUsage.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_BingAdsUserId.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_MsAlias.Deserialize(reader);
				}
				else
				{
					s0_MsAlias.SetNull();
				}
				s0_UcmUserId.Deserialize(reader);
				s0_NumofMonth.Deserialize(reader);
				if ((___masking___[0] & 4) != 4)
				{
					s0_LastMonth.Deserialize(reader);
				}
				else
				{
					s0_LastMonth.SetNull();
				}
				s0_NumofWeek.Deserialize(reader);
				s0_TotalUsage.Deserialize(reader);
			}
		}
	}


	public class Row_BA9089D6CEAA8BB5 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("BingAdsUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("MsAlias", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UcmUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("FreqSegment", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofMonth", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("LastMonth", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofWeek", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("TotalUsage", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_BingAdsUserId;
		public ScopeRuntime.IntegerColumnData BingAdsUserId
		{
			get { return s0_BingAdsUserId; }
			set 
			{
				s0_BingAdsUserId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_MsAlias;
		public ScopeRuntime.StringColumnData MsAlias
		{
			get { return s0_MsAlias; }
			set 
			{
				s0_MsAlias = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UcmUserId;
		public ScopeRuntime.IntegerColumnData UcmUserId
		{
			get { return s0_UcmUserId; }
			set 
			{
				s0_UcmUserId = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_FreqSegment;
		public ScopeRuntime.StringColumnData FreqSegment
		{
			get { return s0_FreqSegment; }
			set 
			{
				s0_FreqSegment = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_NumofMonth;
		public ScopeRuntime.IntegerColumnData NumofMonth
		{
			get { return s0_NumofMonth; }
			set 
			{
				s0_NumofMonth = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_LastMonth;
		public ScopeRuntime.StringColumnData LastMonth
		{
			get { return s0_LastMonth; }
			set 
			{
				s0_LastMonth = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_NumofWeek;
		public ScopeRuntime.IntegerColumnData NumofWeek
		{
			get { return s0_NumofWeek; }
			set 
			{
				s0_NumofWeek = value;
				_columns[6] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_TotalUsage;
		public ScopeRuntime.IntegerColumnData TotalUsage
		{
			get { return s0_TotalUsage; }
			set 
			{
				s0_TotalUsage = value;
				_columns[7] = value;
			}
		}
		public Row_BA9089D6CEAA8BB5(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_BA9089D6CEAA8BB5(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_BA9089D6CEAA8BB5() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_BingAdsUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_MsAlias = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_UcmUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 3:
					{
						s0_FreqSegment = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 4:
					{
						s0_NumofMonth = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 5:
					{
						s0_LastMonth = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 6:
					{
						s0_NumofWeek = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 7:
					{
						s0_TotalUsage = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_MsAlias.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_FreqSegment.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (s0_LastMonth.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 3);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_BingAdsUserId.Serialize(writer);
			if (!s0_MsAlias.IsNull())
			{
				s0_MsAlias.Serialize(writer);
			}
			s0_UcmUserId.Serialize(writer);
			if (!s0_FreqSegment.IsNull())
			{
				s0_FreqSegment.Serialize(writer);
			}
			s0_NumofMonth.Serialize(writer);
			if (!s0_LastMonth.IsNull())
			{
				s0_LastMonth.Serialize(writer);
			}
			s0_NumofWeek.Serialize(writer);
			s0_TotalUsage.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_BingAdsUserId.Deserialize(reader);
				s0_MsAlias.Deserialize(reader);
				s0_UcmUserId.Deserialize(reader);
				s0_FreqSegment.Deserialize(reader);
				s0_NumofMonth.Deserialize(reader);
				s0_LastMonth.Deserialize(reader);
				s0_NumofWeek.Deserialize(reader);
				s0_TotalUsage.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_BingAdsUserId.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_MsAlias.Deserialize(reader);
				}
				else
				{
					s0_MsAlias.SetNull();
				}
				s0_UcmUserId.Deserialize(reader);
				if ((___masking___[0] & 4) != 4)
				{
					s0_FreqSegment.Deserialize(reader);
				}
				else
				{
					s0_FreqSegment.SetNull();
				}
				s0_NumofMonth.Deserialize(reader);
				if ((___masking___[0] & 8) != 8)
				{
					s0_LastMonth.Deserialize(reader);
				}
				else
				{
					s0_LastMonth.SetNull();
				}
				s0_NumofWeek.Deserialize(reader);
				s0_TotalUsage.Deserialize(reader);
			}
		}
	}

	public class ScopeSStreamOutput_2 : SStreamOutputter
	{
		Row_BA9089D6CEAA8BB5 columnGroupRow_0 = new Row_BA9089D6CEAA8BB5 (new Schema("BingAdsUserId:int,MsAlias:string,UcmUserId:int,FreqSegment:string,NumofMonth:int,LastMonth:string,NumofWeek:int,TotalUsage:int"));
		public ScopeSStreamOutput_2()
		{
			_isSerial = true;
			_blockSize = 4194304;
		}
		public override void OutputRow (Row row)
		{
			columnGroupRow_0.BingAdsUserId = ((Row_BA9089D6CEAA8BB5)row).BingAdsUserId;
			columnGroupRow_0.MsAlias = ((Row_BA9089D6CEAA8BB5)row).MsAlias;
			columnGroupRow_0.UcmUserId = ((Row_BA9089D6CEAA8BB5)row).UcmUserId;
			columnGroupRow_0.FreqSegment = ((Row_BA9089D6CEAA8BB5)row).FreqSegment;
			columnGroupRow_0.NumofMonth = ((Row_BA9089D6CEAA8BB5)row).NumofMonth;
			columnGroupRow_0.LastMonth = ((Row_BA9089D6CEAA8BB5)row).LastMonth;
			columnGroupRow_0.NumofWeek = ((Row_BA9089D6CEAA8BB5)row).NumofWeek;
			columnGroupRow_0.TotalUsage = ((Row_BA9089D6CEAA8BB5)row).TotalUsage;
			_writers[0].AppendRow (columnGroupRow_0 );
			
		}
	}


	public class Row_F7146980BD03F3F8 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Start", ScopeRuntime.ColumnDataType.DateTime, typeof(System.DateTime), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Region", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Duration", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Urls", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("ClickedUrls", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_UserId;
		public ScopeRuntime.IntegerColumnData UserId
		{
			get { return s0_UserId; }
			set 
			{
				s0_UserId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.DateTimeColumnData s0_Start;
		public ScopeRuntime.DateTimeColumnData Start
		{
			get { return s0_Start; }
			set 
			{
				s0_Start = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Region;
		public ScopeRuntime.StringColumnData Region
		{
			get { return s0_Region; }
			set 
			{
				s0_Region = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Query;
		public ScopeRuntime.StringColumnData Query
		{
			get { return s0_Query; }
			set 
			{
				s0_Query = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_Duration;
		public ScopeRuntime.IntegerColumnData Duration
		{
			get { return s0_Duration; }
			set 
			{
				s0_Duration = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Urls;
		public ScopeRuntime.StringColumnData Urls
		{
			get { return s0_Urls; }
			set 
			{
				s0_Urls = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_ClickedUrls;
		public ScopeRuntime.StringColumnData ClickedUrls
		{
			get { return s0_ClickedUrls; }
			set 
			{
				s0_ClickedUrls = value;
				_columns[6] = value;
			}
		}
		public Row_F7146980BD03F3F8(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_F7146980BD03F3F8(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_F7146980BD03F3F8() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_UserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_Start = (ScopeRuntime.DateTimeColumnData)value;
						break;
					}
					case 2:
					{
						s0_Region = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 3:
					{
						s0_Query = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 4:
					{
						s0_Duration = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 5:
					{
						s0_Urls = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 6:
					{
						s0_ClickedUrls = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Region.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Query.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (s0_Urls.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 3);
			}
			if (s0_ClickedUrls.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 4);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_UserId.Serialize(writer);
			s0_Start.Serialize(writer);
			if (!s0_Region.IsNull())
			{
				s0_Region.Serialize(writer);
			}
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
			s0_Duration.Serialize(writer);
			if (!s0_Urls.IsNull())
			{
				s0_Urls.Serialize(writer);
			}
			if (!s0_ClickedUrls.IsNull())
			{
				s0_ClickedUrls.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_UserId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				s0_Region.Deserialize(reader);
				s0_Query.Deserialize(reader);
				s0_Duration.Deserialize(reader);
				s0_Urls.Deserialize(reader);
				s0_ClickedUrls.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_UserId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Region.Deserialize(reader);
				}
				else
				{
					s0_Region.SetNull();
				}
				if ((___masking___[0] & 4) != 4)
				{
					s0_Query.Deserialize(reader);
				}
				else
				{
					s0_Query.SetNull();
				}
				s0_Duration.Deserialize(reader);
				if ((___masking___[0] & 8) != 8)
				{
					s0_Urls.Deserialize(reader);
				}
				else
				{
					s0_Urls.SetNull();
				}
				if ((___masking___[0] & 16) != 16)
				{
					s0_ClickedUrls.Deserialize(reader);
				}
				else
				{
					s0_ClickedUrls.SetNull();
				}
			}
		}
	}

	public class ScopeSStreamOutput_3 : SStreamOutputter
	{
		Row_F7146980BD03F3F8 columnGroupRow_0 = new Row_F7146980BD03F3F8 (new Schema("UserId:int,Start:DateTime,Region:string,Query:string,Duration:int,Urls:string,ClickedUrls:string"));
		public ScopeSStreamOutput_3()
		{
			_isSerial = true;
			_blockSize = 4194304;
		}
		public override void OutputRow (Row row)
		{
			columnGroupRow_0.UserId = ((Row_F7146980BD03F3F8)row).UserId;
			columnGroupRow_0.Start = ((Row_F7146980BD03F3F8)row).Start;
			columnGroupRow_0.Region = ((Row_F7146980BD03F3F8)row).Region;
			columnGroupRow_0.Query = ((Row_F7146980BD03F3F8)row).Query;
			columnGroupRow_0.Duration = ((Row_F7146980BD03F3F8)row).Duration;
			columnGroupRow_0.Urls = ((Row_F7146980BD03F3F8)row).Urls;
			columnGroupRow_0.ClickedUrls = ((Row_F7146980BD03F3F8)row).ClickedUrls;
			_writers[0].AppendRow (columnGroupRow_0 );
			
		}
	}


	public class Row_Region_String_Duration_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Region", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Duration", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.StringColumnData s0_Region;
		public ScopeRuntime.StringColumnData Region
		{
			get { return s0_Region; }
			set 
			{
				s0_Region = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_Duration;
		public ScopeRuntime.IntegerColumnData Duration
		{
			get { return s0_Duration; }
			set 
			{
				s0_Duration = value;
				_columns[1] = value;
			}
		}
		public Row_Region_String_Duration_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Region_String_Duration_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Region_String_Duration_Integer() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_Region = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_Duration = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Region.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_Region.IsNull())
			{
				s0_Region.Serialize(writer);
			}
			s0_Duration.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Region.Deserialize(reader);
				s0_Duration.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_Region.Deserialize(reader);
				}
				else
				{
					s0_Region.SetNull();
				}
				s0_Duration.Deserialize(reader);
			}
		}
	}


	public class Row_Region_String_TotalDuration_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Region", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("TotalDuration", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.StringColumnData s0_Region;
		public ScopeRuntime.StringColumnData Region
		{
			get { return s0_Region; }
			set 
			{
				s0_Region = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_TotalDuration;
		public ScopeRuntime.IntegerColumnData TotalDuration
		{
			get { return s0_TotalDuration; }
			set 
			{
				s0_TotalDuration = value;
				_columns[1] = value;
			}
		}
		public Row_Region_String_TotalDuration_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Region_String_TotalDuration_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Region_String_TotalDuration_Integer() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_Region = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_TotalDuration = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Region.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_Region.IsNull())
			{
				s0_Region.Serialize(writer);
			}
			s0_TotalDuration.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Region.Deserialize(reader);
				s0_TotalDuration.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_Region.Deserialize(reader);
				}
				else
				{
					s0_Region.SetNull();
				}
				s0_TotalDuration.Deserialize(reader);
			}
		}
	}


	public class ScopeGrouper_1 : Processor
	{
		//  Member variables used for aggregation
		byte[] Region;

		MySum_Integer s0_TotalDuration_accum;
		public override IEnumerable<Row> Process(RowSet s0_input, Row s0_outRow, string[] s0_args)
		{
			//  Scope variables
			Row_Region_String_TotalDuration_Integer s0_outputRow = (Row_Region_String_TotalDuration_Integer)s0_outRow;
			IEnumerator<Row> s0_enumerator = s0_input.Rows.GetEnumerator();
			
			if (s0_enumerator.MoveNext())
			{
				bool s0_alldone = false;
				Row_Region_String_TotalDuration_Integer s0_row = (Row_Region_String_TotalDuration_Integer)s0_enumerator.Current;
				for (;;)
				{
					Region = s0_row.Region.Binary;
					s0_TotalDuration_accum = new MySum_Integer();
					s0_TotalDuration_accum.Initialize();
					s0_TotalDuration_accum.Add(s0_row.TotalDuration.Integer);
					for (;;)
					{
						s0_alldone = !s0_enumerator.MoveNext();
						if (s0_alldone) break;
						s0_row = (Row_Region_String_TotalDuration_Integer)s0_enumerator.Current;
						if (ColumnDataComparer.Compare(Region, s0_row["Region"].Binary) != 0) 
							break;
						s0_TotalDuration_accum.Add(s0_row.TotalDuration.Integer);
					}  // end of all rows with this key
					s0_outputRow.Region.Set(Region);
					s0_outputRow.TotalDuration.Set(s0_TotalDuration_accum.Finalize());
					yield return s0_outputRow;
					if (s0_alldone) break;
				}  // end of all keys
			}
		}
		public override void MemoryLoadNotification(uint loadPercent, ulong availableBytes)
		{
			if (s0_TotalDuration_accum != null) { s0_TotalDuration_accum.MemoryLoadNotification(loadPercent, availableBytes); }
		}
	}


	public class Row_77740F60D5951C2A : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("SepalLength", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("SepalWidth", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("PetalLength", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("PetalWidth", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Name", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.DoubleColumnData s0_SepalLength;
		public ScopeRuntime.DoubleColumnData SepalLength
		{
			get { return s0_SepalLength; }
			set 
			{
				s0_SepalLength = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_SepalWidth;
		public ScopeRuntime.DoubleColumnData SepalWidth
		{
			get { return s0_SepalWidth; }
			set 
			{
				s0_SepalWidth = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_PetalLength;
		public ScopeRuntime.DoubleColumnData PetalLength
		{
			get { return s0_PetalLength; }
			set 
			{
				s0_PetalLength = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_PetalWidth;
		public ScopeRuntime.DoubleColumnData PetalWidth
		{
			get { return s0_PetalWidth; }
			set 
			{
				s0_PetalWidth = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Name;
		public ScopeRuntime.StringColumnData Name
		{
			get { return s0_Name; }
			set 
			{
				s0_Name = value;
				_columns[4] = value;
			}
		}
		public Row_77740F60D5951C2A(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_77740F60D5951C2A(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_77740F60D5951C2A() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_SepalLength = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 1:
					{
						s0_SepalWidth = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 2:
					{
						s0_PetalLength = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 3:
					{
						s0_PetalWidth = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 4:
					{
						s0_Name = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Name.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_SepalLength.Serialize(writer);
			s0_SepalWidth.Serialize(writer);
			s0_PetalLength.Serialize(writer);
			s0_PetalWidth.Serialize(writer);
			if (!s0_Name.IsNull())
			{
				s0_Name.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_SepalLength.Deserialize(reader);
				s0_SepalWidth.Deserialize(reader);
				s0_PetalLength.Deserialize(reader);
				s0_PetalWidth.Deserialize(reader);
				s0_Name.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_SepalLength.Deserialize(reader);
				s0_SepalWidth.Deserialize(reader);
				s0_PetalLength.Deserialize(reader);
				s0_PetalWidth.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Name.Deserialize(reader);
				}
				else
				{
					s0_Name.SetNull();
				}
			}
		}
	}


	public class Row_Start_DateTime_Market_String_DwellTime_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Start", ScopeRuntime.ColumnDataType.DateTime, typeof(System.DateTime), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTime", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.DateTimeColumnData s0_Start;
		public ScopeRuntime.DateTimeColumnData Start
		{
			get { return s0_Start; }
			set 
			{
				s0_Start = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_DwellTime;
		public ScopeRuntime.IntegerColumnData DwellTime
		{
			get { return s0_DwellTime; }
			set 
			{
				s0_DwellTime = value;
				_columns[2] = value;
			}
		}
		public Row_Start_DateTime_Market_String_DwellTime_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Start_DateTime_Market_String_DwellTime_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Start_DateTime_Market_String_DwellTime_Integer() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_Start = (ScopeRuntime.DateTimeColumnData)value;
						break;
					}
					case 1:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_DwellTime = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_Start.Serialize(writer);
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			s0_DwellTime.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Start.Deserialize(reader);
				s0_Market.Deserialize(reader);
				s0_DwellTime.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_Start.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				s0_DwellTime.Deserialize(reader);
			}
		}
	}


	public class Row_DwellTimeInMinutes_Double_Start_DateTime_Market_String : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTimeInMinutes", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Start", ScopeRuntime.ColumnDataType.DateTime, typeof(System.DateTime), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.DoubleColumnData s0_DwellTimeInMinutes;
		public ScopeRuntime.DoubleColumnData DwellTimeInMinutes
		{
			get { return s0_DwellTimeInMinutes; }
			set 
			{
				s0_DwellTimeInMinutes = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.DateTimeColumnData s0_Start;
		public ScopeRuntime.DateTimeColumnData Start
		{
			get { return s0_Start; }
			set 
			{
				s0_Start = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[2] = value;
			}
		}
		public Row_DwellTimeInMinutes_Double_Start_DateTime_Market_String(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_DwellTimeInMinutes_Double_Start_DateTime_Market_String(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_DwellTimeInMinutes_Double_Start_DateTime_Market_String() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_DwellTimeInMinutes = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 1:
					{
						s0_Start = (ScopeRuntime.DateTimeColumnData)value;
						break;
					}
					case 2:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_DwellTimeInMinutes.Serialize(writer);
			s0_Start.Serialize(writer);
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_DwellTimeInMinutes.Deserialize(reader);
				s0_Start.Deserialize(reader);
				s0_Market.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_DwellTimeInMinutes.Deserialize(reader);
				s0_Start.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
			}
		}
	}


	public class ScopeTransformer_6 : ScopeRuntime.Processor
	{
		public override IEnumerable<Row> Process(RowSet input, Row outputRow, string[] args)
		{
			Row_DwellTimeInMinutes_Double_Start_DateTime_Market_String outRow = (Row_DwellTimeInMinutes_Double_Start_DateTime_Market_String)outputRow;
			foreach (Row_Start_DateTime_Market_String_DwellTime_Integer row in input.Rows)
			{
				int exceptionIndex = 0;
				try
				{
					DateTime col_Start = row.Start.DateTime;
					StringColumnData col_Market = row.Market;
					int col_DwellTime = row.DwellTime.Integer;

					outRow.DwellTimeInMinutes.Set((MyHelper.ClassUDO.SecondsToMinutes(col_DwellTime)));
					exceptionIndex++;
					outRow.Start.Set((col_Start));
					exceptionIndex++;
					outRow.Market.Set((col_Market));
					exceptionIndex++;
				}
				catch (Exception exception)
				{
					ScopeEngineManaged.ExceptionHelper.WrapExpressionException(exceptionsInfo[exceptionIndex], row.Dump(), exception);
				}
				yield return outRow;
			} //end of foreach Row_Start_DateTime_Market_String_DwellTime_Integer
		}
		public static string[] exceptionsInfo = 
		{
			@"MyHelper.ClassUDO.SecondsToMinutes(DwellTime)",
			@"Start",
			@"Market",
		};
	}


	public class Row_Start_DateTime_Market_String_DwellTimeInMinutes_Double : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Start", ScopeRuntime.ColumnDataType.DateTime, typeof(System.DateTime), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTimeInMinutes", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
		};

		ScopeRuntime.DateTimeColumnData s0_Start;
		public ScopeRuntime.DateTimeColumnData Start
		{
			get { return s0_Start; }
			set 
			{
				s0_Start = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_DwellTimeInMinutes;
		public ScopeRuntime.DoubleColumnData DwellTimeInMinutes
		{
			get { return s0_DwellTimeInMinutes; }
			set 
			{
				s0_DwellTimeInMinutes = value;
				_columns[2] = value;
			}
		}
		public Row_Start_DateTime_Market_String_DwellTimeInMinutes_Double(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Start_DateTime_Market_String_DwellTimeInMinutes_Double(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Start_DateTime_Market_String_DwellTimeInMinutes_Double() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_Start = (ScopeRuntime.DateTimeColumnData)value;
						break;
					}
					case 1:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_DwellTimeInMinutes = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_Start.Serialize(writer);
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			s0_DwellTimeInMinutes.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Start.Deserialize(reader);
				s0_Market.Deserialize(reader);
				s0_DwellTimeInMinutes.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_Start.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				s0_DwellTimeInMinutes.Deserialize(reader);
			}
		}
	}


	public class ScopeFilterTransformer_12 : ScopeRuntime.Processor
	{
		public override IEnumerable<Row> Process(RowSet input, Row outputRow, string[] args)
		{
			Row_Start_DateTime_Market_String_DwellTimeInMinutes_Double outRow = (Row_Start_DateTime_Market_String_DwellTimeInMinutes_Double)outputRow;
			foreach(Row_Start_DateTime_Market_String_DwellTime_Integer row in input.Rows)
			{
				DateTime col_Start = row.Start.DateTime;
				StringColumnData col_Market = row.Market;
				int col_DwellTime = row.DwellTime.Integer;
				bool bPicked = false;
				int exceptionIndex = 0;
				try
				{
					{
						bPicked = true;
						outRow.Start.Set((col_Start));
						exceptionIndex++;
						outRow.Market.Set((col_Market));
						exceptionIndex++;
						outRow.DwellTimeInMinutes.Set((MyHelper.ClassUDO.SecondsToMinutes(col_DwellTime)));
						exceptionIndex++;
					}
				}
				catch (Exception exception)
				{
					ScopeEngineManaged.ExceptionHelper.WrapExpressionException(exceptionsInfo[exceptionIndex], row.Dump(), exception);
				}
				if(bPicked)
				{
					yield return outRow;
				}
			} // end of foreach Row_Start_DateTime_Market_String_DwellTime_Integer
		}
		public static string[] exceptionsInfo = 
		{
			@"Start",
			@"Market",
			@"MyHelper.ClassUDO.SecondsToMinutes(DwellTime)",
		};
	}


	public class Row_BingAdsUserId_Integer_MsAlias_String_UcmUserId_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("BingAdsUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("MsAlias", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UcmUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_BingAdsUserId;
		public ScopeRuntime.IntegerColumnData BingAdsUserId
		{
			get { return s0_BingAdsUserId; }
			set 
			{
				s0_BingAdsUserId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_MsAlias;
		public ScopeRuntime.StringColumnData MsAlias
		{
			get { return s0_MsAlias; }
			set 
			{
				s0_MsAlias = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UcmUserId;
		public ScopeRuntime.IntegerColumnData UcmUserId
		{
			get { return s0_UcmUserId; }
			set 
			{
				s0_UcmUserId = value;
				_columns[2] = value;
			}
		}
		public Row_BingAdsUserId_Integer_MsAlias_String_UcmUserId_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_BingAdsUserId_Integer_MsAlias_String_UcmUserId_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_BingAdsUserId_Integer_MsAlias_String_UcmUserId_Integer() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_BingAdsUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_MsAlias = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_UcmUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_MsAlias.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_BingAdsUserId.Serialize(writer);
			if (!s0_MsAlias.IsNull())
			{
				s0_MsAlias.Serialize(writer);
			}
			s0_UcmUserId.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_BingAdsUserId.Deserialize(reader);
				s0_MsAlias.Deserialize(reader);
				s0_UcmUserId.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_BingAdsUserId.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_MsAlias.Deserialize(reader);
				}
				else
				{
					s0_MsAlias.SetNull();
				}
				s0_UcmUserId.Deserialize(reader);
			}
		}
	}


	public class Row_201904760BAF1F64 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("BingAdsUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("MsAlias", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UcmUserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("NumofMonth", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("LastMonth", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("TotalUsage", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_BingAdsUserId;
		public ScopeRuntime.IntegerColumnData BingAdsUserId
		{
			get { return s0_BingAdsUserId; }
			set 
			{
				s0_BingAdsUserId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_MsAlias;
		public ScopeRuntime.StringColumnData MsAlias
		{
			get { return s0_MsAlias; }
			set 
			{
				s0_MsAlias = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_UcmUserId;
		public ScopeRuntime.IntegerColumnData UcmUserId
		{
			get { return s0_UcmUserId; }
			set 
			{
				s0_UcmUserId = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_NumofMonth;
		public ScopeRuntime.IntegerColumnData NumofMonth
		{
			get { return s0_NumofMonth; }
			set 
			{
				s0_NumofMonth = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_LastMonth;
		public ScopeRuntime.StringColumnData LastMonth
		{
			get { return s0_LastMonth; }
			set 
			{
				s0_LastMonth = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_TotalUsage;
		public ScopeRuntime.IntegerColumnData TotalUsage
		{
			get { return s0_TotalUsage; }
			set 
			{
				s0_TotalUsage = value;
				_columns[5] = value;
			}
		}
		public Row_201904760BAF1F64(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_201904760BAF1F64(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_201904760BAF1F64() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_BingAdsUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_MsAlias = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_UcmUserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 3:
					{
						s0_NumofMonth = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 4:
					{
						s0_LastMonth = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 5:
					{
						s0_TotalUsage = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_MsAlias.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_LastMonth.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_BingAdsUserId.Serialize(writer);
			if (!s0_MsAlias.IsNull())
			{
				s0_MsAlias.Serialize(writer);
			}
			s0_UcmUserId.Serialize(writer);
			s0_NumofMonth.Serialize(writer);
			if (!s0_LastMonth.IsNull())
			{
				s0_LastMonth.Serialize(writer);
			}
			s0_TotalUsage.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_BingAdsUserId.Deserialize(reader);
				s0_MsAlias.Deserialize(reader);
				s0_UcmUserId.Deserialize(reader);
				s0_NumofMonth.Deserialize(reader);
				s0_LastMonth.Deserialize(reader);
				s0_TotalUsage.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_BingAdsUserId.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_MsAlias.Deserialize(reader);
				}
				else
				{
					s0_MsAlias.SetNull();
				}
				s0_UcmUserId.Deserialize(reader);
				s0_NumofMonth.Deserialize(reader);
				if ((___masking___[0] & 4) != 4)
				{
					s0_LastMonth.Deserialize(reader);
				}
				else
				{
					s0_LastMonth.SetNull();
				}
				s0_TotalUsage.Deserialize(reader);
			}
		}
	}


	public class Row_42AAB829FBD45C8D : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("IId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Start", ScopeRuntime.ColumnDataType.DateTime, typeof(System.DateTime), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTime", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Results", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("ClickedUrls", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_IId;
		public ScopeRuntime.IntegerColumnData IId
		{
			get { return s0_IId; }
			set 
			{
				s0_IId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.DateTimeColumnData s0_Start;
		public ScopeRuntime.DateTimeColumnData Start
		{
			get { return s0_Start; }
			set 
			{
				s0_Start = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Query;
		public ScopeRuntime.StringColumnData Query
		{
			get { return s0_Query; }
			set 
			{
				s0_Query = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_DwellTime;
		public ScopeRuntime.IntegerColumnData DwellTime
		{
			get { return s0_DwellTime; }
			set 
			{
				s0_DwellTime = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Results;
		public ScopeRuntime.StringColumnData Results
		{
			get { return s0_Results; }
			set 
			{
				s0_Results = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_ClickedUrls;
		public ScopeRuntime.StringColumnData ClickedUrls
		{
			get { return s0_ClickedUrls; }
			set 
			{
				s0_ClickedUrls = value;
				_columns[6] = value;
			}
		}
		public Row_42AAB829FBD45C8D(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_42AAB829FBD45C8D(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_42AAB829FBD45C8D() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_IId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_Start = (ScopeRuntime.DateTimeColumnData)value;
						break;
					}
					case 2:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 3:
					{
						s0_Query = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 4:
					{
						s0_DwellTime = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 5:
					{
						s0_Results = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 6:
					{
						s0_ClickedUrls = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Query.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (s0_Results.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 3);
			}
			if (s0_ClickedUrls.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 4);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_IId.Serialize(writer);
			s0_Start.Serialize(writer);
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
			s0_DwellTime.Serialize(writer);
			if (!s0_Results.IsNull())
			{
				s0_Results.Serialize(writer);
			}
			if (!s0_ClickedUrls.IsNull())
			{
				s0_ClickedUrls.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_IId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				s0_Market.Deserialize(reader);
				s0_Query.Deserialize(reader);
				s0_DwellTime.Deserialize(reader);
				s0_Results.Deserialize(reader);
				s0_ClickedUrls.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_IId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				if ((___masking___[0] & 4) != 4)
				{
					s0_Query.Deserialize(reader);
				}
				else
				{
					s0_Query.SetNull();
				}
				s0_DwellTime.Deserialize(reader);
				if ((___masking___[0] & 8) != 8)
				{
					s0_Results.Deserialize(reader);
				}
				else
				{
					s0_Results.SetNull();
				}
				if ((___masking___[0] & 16) != 16)
				{
					s0_ClickedUrls.Deserialize(reader);
				}
				else
				{
					s0_ClickedUrls.SetNull();
				}
			}
		}
	}


	public class Row_54D58AA49E10FB30 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("SepalLength_Mean", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("SepalWidth_Mean", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("PetalLength_Mean", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("PetalWidth_Mean", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Name", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Count", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.DoubleColumnData s0_SepalLength_Mean;
		public ScopeRuntime.DoubleColumnData SepalLength_Mean
		{
			get { return s0_SepalLength_Mean; }
			set 
			{
				s0_SepalLength_Mean = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_SepalWidth_Mean;
		public ScopeRuntime.DoubleColumnData SepalWidth_Mean
		{
			get { return s0_SepalWidth_Mean; }
			set 
			{
				s0_SepalWidth_Mean = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_PetalLength_Mean;
		public ScopeRuntime.DoubleColumnData PetalLength_Mean
		{
			get { return s0_PetalLength_Mean; }
			set 
			{
				s0_PetalLength_Mean = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_PetalWidth_Mean;
		public ScopeRuntime.DoubleColumnData PetalWidth_Mean
		{
			get { return s0_PetalWidth_Mean; }
			set 
			{
				s0_PetalWidth_Mean = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Name;
		public ScopeRuntime.StringColumnData Name
		{
			get { return s0_Name; }
			set 
			{
				s0_Name = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_Count;
		public ScopeRuntime.IntegerColumnData _Count_
		{
			get { return s0_Count; }
			set 
			{
				s0_Count = value;
				_columns[5] = value;
			}
		}
		public Row_54D58AA49E10FB30(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_54D58AA49E10FB30(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_54D58AA49E10FB30() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_SepalLength_Mean = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 1:
					{
						s0_SepalWidth_Mean = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 2:
					{
						s0_PetalLength_Mean = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 3:
					{
						s0_PetalWidth_Mean = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 4:
					{
						s0_Name = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 5:
					{
						s0_Count = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Name.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_SepalLength_Mean.Serialize(writer);
			s0_SepalWidth_Mean.Serialize(writer);
			s0_PetalLength_Mean.Serialize(writer);
			s0_PetalWidth_Mean.Serialize(writer);
			if (!s0_Name.IsNull())
			{
				s0_Name.Serialize(writer);
			}
			s0_Count.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_SepalLength_Mean.Deserialize(reader);
				s0_SepalWidth_Mean.Deserialize(reader);
				s0_PetalLength_Mean.Deserialize(reader);
				s0_PetalWidth_Mean.Deserialize(reader);
				s0_Name.Deserialize(reader);
				s0_Count.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_SepalLength_Mean.Deserialize(reader);
				s0_SepalWidth_Mean.Deserialize(reader);
				s0_PetalLength_Mean.Deserialize(reader);
				s0_PetalWidth_Mean.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Name.Deserialize(reader);
				}
				else
				{
					s0_Name.SetNull();
				}
				s0_Count.Deserialize(reader);
			}
		}
	}


	public class Row_7792A42DFDA6BCF3 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UserId", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Start", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Region", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Duration", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Urls", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("ClickedUrls", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.StringColumnData s0_UserId;
		public ScopeRuntime.StringColumnData UserId
		{
			get { return s0_UserId; }
			set 
			{
				s0_UserId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Start;
		public ScopeRuntime.StringColumnData Start
		{
			get { return s0_Start; }
			set 
			{
				s0_Start = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Region;
		public ScopeRuntime.StringColumnData Region
		{
			get { return s0_Region; }
			set 
			{
				s0_Region = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Query;
		public ScopeRuntime.StringColumnData Query
		{
			get { return s0_Query; }
			set 
			{
				s0_Query = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Duration;
		public ScopeRuntime.StringColumnData Duration
		{
			get { return s0_Duration; }
			set 
			{
				s0_Duration = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Urls;
		public ScopeRuntime.StringColumnData Urls
		{
			get { return s0_Urls; }
			set 
			{
				s0_Urls = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_ClickedUrls;
		public ScopeRuntime.StringColumnData ClickedUrls
		{
			get { return s0_ClickedUrls; }
			set 
			{
				s0_ClickedUrls = value;
				_columns[6] = value;
			}
		}
		public Row_7792A42DFDA6BCF3(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_7792A42DFDA6BCF3(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_7792A42DFDA6BCF3() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_UserId = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_Start = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 2:
					{
						s0_Region = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 3:
					{
						s0_Query = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 4:
					{
						s0_Duration = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 5:
					{
						s0_Urls = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 6:
					{
						s0_ClickedUrls = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_UserId.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Start.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (s0_Region.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 3);
			}
			if (s0_Query.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 4);
			}
			if (s0_Duration.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 5);
			}
			if (s0_Urls.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 6);
			}
			if (s0_ClickedUrls.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 7);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_UserId.IsNull())
			{
				s0_UserId.Serialize(writer);
			}
			if (!s0_Start.IsNull())
			{
				s0_Start.Serialize(writer);
			}
			if (!s0_Region.IsNull())
			{
				s0_Region.Serialize(writer);
			}
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
			if (!s0_Duration.IsNull())
			{
				s0_Duration.Serialize(writer);
			}
			if (!s0_Urls.IsNull())
			{
				s0_Urls.Serialize(writer);
			}
			if (!s0_ClickedUrls.IsNull())
			{
				s0_ClickedUrls.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_UserId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				s0_Region.Deserialize(reader);
				s0_Query.Deserialize(reader);
				s0_Duration.Deserialize(reader);
				s0_Urls.Deserialize(reader);
				s0_ClickedUrls.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_UserId.Deserialize(reader);
				}
				else
				{
					s0_UserId.SetNull();
				}
				if ((___masking___[0] & 4) != 4)
				{
					s0_Start.Deserialize(reader);
				}
				else
				{
					s0_Start.SetNull();
				}
				if ((___masking___[0] & 8) != 8)
				{
					s0_Region.Deserialize(reader);
				}
				else
				{
					s0_Region.SetNull();
				}
				if ((___masking___[0] & 16) != 16)
				{
					s0_Query.Deserialize(reader);
				}
				else
				{
					s0_Query.SetNull();
				}
				if ((___masking___[0] & 32) != 32)
				{
					s0_Duration.Deserialize(reader);
				}
				else
				{
					s0_Duration.SetNull();
				}
				if ((___masking___[0] & 64) != 64)
				{
					s0_Urls.Deserialize(reader);
				}
				else
				{
					s0_Urls.SetNull();
				}
				if ((___masking___[0] & 128) != 128)
				{
					s0_ClickedUrls.Deserialize(reader);
				}
				else
				{
					s0_ClickedUrls.SetNull();
				}
			}
		}
	}


	public class Row_D2CDB106F3B2AF04 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Id", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Start", ScopeRuntime.ColumnDataType.DateTime, typeof(System.DateTime), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Market", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("DwellTime", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Results", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("ClickedUrls", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_Id;
		public ScopeRuntime.IntegerColumnData Id
		{
			get { return s0_Id; }
			set 
			{
				s0_Id = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.DateTimeColumnData s0_Start;
		public ScopeRuntime.DateTimeColumnData Start
		{
			get { return s0_Start; }
			set 
			{
				s0_Start = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Market;
		public ScopeRuntime.StringColumnData Market
		{
			get { return s0_Market; }
			set 
			{
				s0_Market = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Query;
		public ScopeRuntime.StringColumnData Query
		{
			get { return s0_Query; }
			set 
			{
				s0_Query = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_DwellTime;
		public ScopeRuntime.IntegerColumnData DwellTime
		{
			get { return s0_DwellTime; }
			set 
			{
				s0_DwellTime = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Results;
		public ScopeRuntime.StringColumnData Results
		{
			get { return s0_Results; }
			set 
			{
				s0_Results = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_ClickedUrls;
		public ScopeRuntime.StringColumnData ClickedUrls
		{
			get { return s0_ClickedUrls; }
			set 
			{
				s0_ClickedUrls = value;
				_columns[6] = value;
			}
		}
		public Row_D2CDB106F3B2AF04(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_D2CDB106F3B2AF04(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_D2CDB106F3B2AF04() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_Id = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_Start = (ScopeRuntime.DateTimeColumnData)value;
						break;
					}
					case 2:
					{
						s0_Market = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 3:
					{
						s0_Query = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 4:
					{
						s0_DwellTime = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 5:
					{
						s0_Results = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 6:
					{
						s0_ClickedUrls = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Market.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Query.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (s0_Results.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 3);
			}
			if (s0_ClickedUrls.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 4);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_Id.Serialize(writer);
			s0_Start.Serialize(writer);
			if (!s0_Market.IsNull())
			{
				s0_Market.Serialize(writer);
			}
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
			s0_DwellTime.Serialize(writer);
			if (!s0_Results.IsNull())
			{
				s0_Results.Serialize(writer);
			}
			if (!s0_ClickedUrls.IsNull())
			{
				s0_ClickedUrls.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Id.Deserialize(reader);
				s0_Start.Deserialize(reader);
				s0_Market.Deserialize(reader);
				s0_Query.Deserialize(reader);
				s0_DwellTime.Deserialize(reader);
				s0_Results.Deserialize(reader);
				s0_ClickedUrls.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_Id.Deserialize(reader);
				s0_Start.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Market.Deserialize(reader);
				}
				else
				{
					s0_Market.SetNull();
				}
				if ((___masking___[0] & 4) != 4)
				{
					s0_Query.Deserialize(reader);
				}
				else
				{
					s0_Query.SetNull();
				}
				s0_DwellTime.Deserialize(reader);
				if ((___masking___[0] & 8) != 8)
				{
					s0_Results.Deserialize(reader);
				}
				else
				{
					s0_Results.SetNull();
				}
				if ((___masking___[0] & 16) != 16)
				{
					s0_ClickedUrls.Deserialize(reader);
				}
				else
				{
					s0_ClickedUrls.SetNull();
				}
			}
		}
	}


	public static System.Type[] __UdtTypeTable__ =
	{
		
	};

	public static class __OperatorFactory__
	{
		public static ScopeRuntime.Processor Create_Process_23()
		{
			return new ___Scope_Generated_Classes___.ScopeGrouper_1();
		}
		public static string Name_Process_23 = "___Scope_Generated_Classes___.ScopeGrouper_1";
		public static ScopeRuntime.Extractor Create_Extract_25()
		{
			return new  MyTsvExtractor();
		}
		public static string Name_Extract_25 = "___Scope_Generated_Classes___.MyTsvExtractor";
		public static ScopeRuntime.Processor Create_Process_39()
		{
			return new ___Scope_Generated_Classes___.ScopeFilterTransformer_12();
		}
		public static string Name_Process_39 = "___Scope_Generated_Classes___.ScopeFilterTransformer_12";
		public static ScopeRuntime.Processor Create_Process_12()
		{
			return new  FreqProcessor();
		}
		public static string Name_Process_12 = "___Scope_Generated_Classes___.FreqProcessor";
	}
}

	static public class UDTExtensionWrapper
	{
                public static T Create<T>() where T : new() 
                { 
                    return new T(); 
                }

                private static readonly System.Collections.Generic.Dictionary<System.Collections.Generic.IEqualityComparer<string>, byte> StringComparerToByteMap =
                    new System.Collections.Generic.Dictionary<System.Collections.Generic.IEqualityComparer<string>, byte>()
                    {
                        {System.Collections.Generic.EqualityComparer<string>.Default, 0},
                        {System.StringComparer.CurrentCulture, 1},
                        {System.StringComparer.CurrentCultureIgnoreCase, 2},
                        {System.StringComparer.InvariantCulture, 3},
                        {System.StringComparer.InvariantCultureIgnoreCase, 4},
                        {System.StringComparer.Ordinal, 5},
                        {System.StringComparer.OrdinalIgnoreCase, 6},
                    };

                private static readonly System.Collections.Generic.Dictionary<byte, System.Collections.Generic.IEqualityComparer<string>> ByteToStringComparerMap =
                    System.Linq.Enumerable.ToDictionary(StringComparerToByteMap, kvp => kvp.Value, kvp => kvp.Key);

                public static void Read(BinaryValueReader reader, out System.StringComparer value)
                {
                    byte comparerKey;
                    reader.Read(out comparerKey);
                    value = ByteToStringComparerMap[comparerKey] as System.StringComparer;
                }

                public static void Write(BinaryValueWriter writer, System.StringComparer value)
                {
                    // If System.StringComparer is not one of the 6 we recognize, comparerKey should be 0.
                    byte comparerKey;
                    StringComparerToByteMap.TryGetValue(value as System.Collections.Generic.IEqualityComparer<string> ?? System.Collections.Generic.EqualityComparer<string>.Default, out comparerKey);
                    writer.Write(comparerKey);
                }

                static public ScopeStruct       ScopeClone(this ScopeStruct value, ReferenceHashTable<object> seenObject)
                {
                    return (ScopeStruct)new StructColumnData(value).Clone().Value;
                }

                static public ScopeMap<K,V>     ScopeClone<K,V>(this ScopeMap<K,V> value, ReferenceHashTable<object> seenObject)
                {
                    return (ScopeMap<K,V>)new MapColumnData<K,V>(value).Clone().Value;
                }

                static public ScopeArray<T>     ScopeClone<T>(this ScopeArray<T> value, ReferenceHashTable<object> seenObject)
                {
                    return (ScopeArray<T>)new ArrayColumnData<T>(value).Clone().Value;
                }

                static public void Write<T>(BinaryValueWriter writer, ScopeArray<T> v)
                {
                    writer.Write(v);
                }

                static public void Read<T>(BinaryValueReader reader, out ScopeArray<T> v)
                {
                    reader.Read(out v);
                } 

                static public void Write<K,V>(BinaryValueWriter writer, ScopeMap<K,V> v)
                {
                    writer.Write(v);
                }

                static public void Read<K,V>(BinaryValueReader reader, out ScopeMap<K,V> v)
                {
                    reader.Read(out v);
                }                 
                

	}