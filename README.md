# turtle_sample

# 実行
    ターミナル１
    $ roscore

    ターミナル２
    $ rosrun turtlesim turtlesim_node

    ターミナル３
    $ rosrus (パッケージ名) (ノード名)

# パッケージ確認順序
    1. turtle_publish
    2. turtle_subscribe

# パッケージ
1. パッケージ作成
    $ catkin_create_pkc (パッケージ名)

2. フォルダ構造
    >パッケージ
        >config
            >(パッケージ名).yaml
        >launch
            >(パッケージ名).launch
        >src
            >(パッケージ名).cpp
        >CMakeLists.txt
        >package.xml