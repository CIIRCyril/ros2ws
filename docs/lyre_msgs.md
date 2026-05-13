# lyre_msgs

The `lyre_msgs` package defines the custom ROS 2 message and service types used by the robot's audio subsystem (`lyre` / `audio` packages). It covers the full audio pipeline: speech recognition (ASR — keyword wakeup, continuous transcription, and events), text-to-speech (TTS events), audio playback (play file/URL/text/binary, pause, resume, stop, progress), and large-language-model (LLM) integration events. These interfaces allow any other ROS 2 node to trigger audio actions or react to voice-recognition results without depending on the audio hardware directly.

## Message types (`lyre_msgs/msg`)

| Type | Topic / Description |
|------|---------------------|
| `AsrKeyword` | `/audio_asr/keyword` – keyword wakeup result |
| `AsrIat` | `/audio_asr/iat` – continuous ASR transcription |
| `AsrEvent` | `/audio_asr/event` – ASR state events (wakeup, sleep, error …) |
| `TtsEvent` | `/audio_tts/event` – TTS completion/error events |
| `PlayEvent` | `/audio_play/event` – playback lifecycle events |
| `PlayProgress` | `/audio_play/progress` – playback position & duration |
| `LlmEvent` | LLM dialogue events |
| `LlmRst` | LLM response result |

## Examples

### Listen for keyword wakeup events

```bash
ros2 topic echo /audio_asr/keyword
```

### Listen for speech-to-text transcriptions

```bash
ros2 topic echo /audio_asr/iat
```

### Play a local audio file

```bash
ros2 service call /audio_play/play_file lyre_msgs/srv/PlayFile \
  "{path: \"/home/nvidia/data/speech/builtin/100000.mp3\"}"
```

### Play text as speech (TTS)

```bash
ros2 service call /audio_play/play_text lyre_msgs/srv/PlayText \
  '{text: "Hello, I am Cyril"}'
```

### Pause / resume / stop playback

```bash
ros2 service call /audio_play/pause  lyre_msgs/srv/PlayPause
ros2 service call /audio_play/resume lyre_msgs/srv/PlayResume
ros2 service call /audio_play/stop   lyre_msgs/srv/PlayStop
```

### Python snippet – subscribe to ASR events

```python
import rclpy
from rclpy.node import Node
from lyre_msgs.msg import AsrIat

class AsrListener(Node):
    def __init__(self):
        super().__init__('asr_listener')
        self.create_subscription(AsrIat, '/audio_asr/iat', self.cb, 10)

    def cb(self, msg):
        self.get_logger().info(f'Heard: {msg.text}')

rclpy.init()
rclpy.spin(AsrListener())
```
